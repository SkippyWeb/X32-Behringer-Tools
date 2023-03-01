//
// X32USB.c
//
// Listing and managing the contents of a USB drive connected to
// the X32
//
//  Created on: 14 févr. 2015
//      Author: Patrick-Gilles Maillot
//
//  History:
//
//	ver 0.2: bug fixes
//	ver 0.3: update a few things, preparing for a Windows-based use of some of the functions
//
//
//
// Used here:
//
// Is the USB stick mounted?
//  /-stat/usbmounted (expect i=1)
//
// Number of entries in current directory
//  /-usb/dir/maxpos (expect i= num of entries)
//
// Get all files (directories) names
// For i = 0..num of entries
//  /-usb/dir/iii/name
//
// Enter into directory at index n
//  /-action/recselect ,i n
//
// Set dir pointer to file#
//  /-usb/dir/dirpos ,i n  (What's the meaning of a returned value = 256)
//
// List (set?) file name at current position
//  /-usb/title ,s

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#ifdef __WIN32__
#include <windows.h>
#else
#include <sys/socket.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#endif

typedef enum {
	NIL,			// "Unk"
	VOLUME,			// "Vol"
	PARENT,			// "Par"
	DIR,			// "Dir"
	WAV,			// "Wav"
	SHOW,			// "Shw"
	SCENE,			// "Scn"
	SNIPPET,		// "Snp"
	EFFECTS,		// "Eff"
	PREF,			// "Prf"
	ROUT,			// "Rou"
	CHAN,			// "Chn"
} type;

typedef enum {
	STOP,
	PAUSE,
	PLAY,
} state;

char* fTypeSTR[] = { "Unk", "Vol", "Par", "Dir", "Wav", "Shw", "Scn", "Snp",
		"Eff", "Prf", "Rou", "Chn" };

typedef struct fnode *fPtr;

typedef struct fnode {
	fPtr	fPrev;
	char*	fName;
	type	fType;
	int		index;
	fPtr	fNext;
} fNode;

typedef union endian {	//
	char	cc[4];		//
	int		ii;			// A small union to manage
	float	ff;			// Endian type conversions
} Endian;

// External calls used
extern void Xfdump(char *header, char *buf, int len, int debug);
extern int Xsprint(char *bd, int index, char format, void *bs);
extern int Xfprint(char *bd, int index, char* text, char format, void *bs);

// Private functions
int fSetPrompt();			// set default prompt
type fParse(char* name);	// parse file name and return associated file type
fPtr fFname(char* name);	// parse file name and return pointer to associated tree node
void fUpdatePath_cd();		// update prompt path based on current directory
int f_is_mounted();			// request USB status (mounted = 1; not mounted = 0)
int f_umount();				// unmount USB stick (USB no more available)
int f_stop();				// stop (current wav play) command
int f_pause();				// pause (current wav play) command
int f_resume();				// resume (current wav play) command
int f_tree();				// delete and rebuild tree of current directory
int f_ls();					// directory listing (2 column display id, type and file names)
int f_cd(int fNum);			// change directory from id number
int f_cdName(char* name);	// change directory from file name
int f_play(int fNum);		// play WAV file from id number
int f_playName(char* name);	// play WAV file from file name
int f_load(int fNum);		// load or run command from file id number
int f_loadName(char* name);	// load or run command from file file name
int f_help();				// display help - command reminder

#ifdef __WIN32__
#define millisleep(x)	Sleep((x))
#else
#define millisleep(x)	usleep((x)*1000)
#endif

#define LINEMAX				256
#define BSIZE				512

int X32debug = 0;
int X32verbose = 0;
//
//
// Macros:
//
#define fTalloc 		malloc(sizeof(fNode));
#define fTfree(a)		free(a);
//
#define RPOLL													\
	do {														\
		FD_ZERO (&ufds);										\
		FD_SET (Xfd, &ufds);									\
		p_status = select(Xfd+1,&ufds,NULL,NULL,&timeout);		\
	} while (0);

//
//

#define RECV													\
do {															\
	r_len = recvfrom(Xfd, r_buf, BSIZE, 0, 0, 0);				\
	if (X32verbose) {Xfdump("X->", r_buf, r_len, X32debug);}	\
} while (0);

#define SEND													\
do {															\
	if (X32verbose) {Xfdump("->X", s_buf, s_len, X32debug);}	\
	if (s_delay) millisleep(s_delay);							\
	if (sendto(Xfd, s_buf, s_len, 0, Xip_addr, Xip_len) < 0) {	\
		perror("Error while sending data");						\
		exit(EXIT_FAILURE);										\
	}															\
} while(0);

//
// Global data
//
struct	sockaddr_in Xip;
struct	sockaddr* Xip_addr = (struct sockaddr *) &Xip;
int		Xfd;				// our socket
int		p_status;
char	Xip_str[20], Xport_str[8];
int		r_len, s_len;
char	r_buf[BSIZE];
char	s_buf[BSIZE];
int		s_delay;
//
int		zero = 0;
int		one = 1;
int		two = 2;
int		i, j, k, num_files, fXor;
char	tmpstr[32];
fPtr	fTreetop, fTree;
int		fLpos, fNum, fNameLength;
int		fUSB_not_Mounted = 1;
state	f_State = STOP;

union {
	char cc[128];
	int ii[128 / sizeof(int)];
} X32prompt;

Endian endian;					// used for endian conversions
Endian Xmounted = { "$:" };		// default/mounted root prompt
Endian Xnot_mounted = { ">:" };	// default/non mounted root prompt

//
struct timeval timeout;
fd_set ufds;
#ifdef __WIN32__
WSADATA wsa;
int Xip_len = sizeof(Xip);			// length of addresses
unsigned long mode;
#else
socklen_t Xip_len = sizeof(Xip);	// length of addresses
#endif

///////////////////////////////////////////////////////////////
// Private functions:
//
//
// set default prompt
int fSetPrompt() {
	if (f_is_mounted()) {
		X32prompt.ii[0] = Xmounted.ii;
	} else {
		printf("X32 USB device not found\n");
		X32prompt.ii[0] = Xnot_mounted.ii;
	}
	return 1;
}

//
// parse file name and return pointer to associated tree node
//
fPtr fFname(char* str) {
//
// Find str as a filename in fTree nodes
	while (*str == ' ')
		++str; // skip all spaces
	fTree = fTreetop;
	while (fTree) {
		if (fTree->fName[0] == '[') {
			if (strncmp(fTree->fName + 1, str, strlen(fTree->fName) - 2) == 0)
				return fTree;
		} else {
			if (strcmp(fTree->fName, str) == 0)
				return fTree;
		}
		fTree = fTree->fNext;
	}
	return NULL;
}

//
// update prompt path based on current directory
//
void fUpdatePath_cd() {
	char *s;
//
// We build the shell prompt based on the directory changes (cd) commands already entered.
// The initial prompt is ">:" (Xnot_mounted) if no USB drive is detected and
// "$:" if a USB drive is detected.
//
// Issuing cd commands will change the prompt to "dir1/dir2/.../dirn:" by concatenation
// of the folder name to the existing prompt string (X32prompt),
// and cd .. (parent) will removed "/dirn" from the prompt string (X32prompt)
	if (fTree->fType == PARENT) {
		if ((s = strrchr(X32prompt.cc, '/')) != NULL) {
			*s++ = ':';
			*s = 0;
		} else {
			X32prompt.ii[0] = Xmounted.ii;
		}
	} else {
		X32prompt.cc[strlen(X32prompt.cc) - 1] = '/';
		strcat(X32prompt.cc, fTree->fName + 1);
		i = strlen(X32prompt.cc);
		X32prompt.cc[i - 1] = ':';
		X32prompt.cc[i] = 0;
	}
}

//
// parse file name and return associated file type
//
type fParse(char *name) {
	int fLen, i;
	//
	// Directory types cases (PARENT, ...}
	if (strcmp(name, "[..]") == 0)
		return PARENT;
	if (strcmp(name, "[System Volume Information]") == 0)
		return VOLUME;
	if ((name[0] == '[') && (name[strlen(name) - 1] == ']'))
		return DIR;
	//
	// File types cases
	fLen = strlen(name);
	for (i = fLen; i > -1; i--) {
		if (name[i] == '.') {
			i += 1;
			//
			// we use strcasecmp() for comparing strings; This is part of the gnu
			// libc and works similarly to strcmp(), but will not differentiate
			// lower and upper case characters. In other words "wav" and "WAV" are
			// equivalent. More info at http://www.gnu.org/software/libc/manual
			if (strcasecmp(name + i, "wav") == 0)
				return WAV;
			if (strcasecmp(name + i, "shw") == 0)
				return SHOW;
			if (strcasecmp(name + i, "scn") == 0)
				return SCENE;
			if (strcasecmp(name + i, "snp") == 0)
				return SNIPPET;
			if (strcasecmp(name + i, "efx") == 0)
				return EFFECTS;
			if (strcasecmp(name + i, "prf") == 0)
				return PREF;
			if (strcasecmp(name + i, "rou") == 0)
				return ROUT;
			if (strcasecmp(name + i, "chn") == 0)
				return CHAN;
			return NIL;
		}
	}
	return NIL;
}

//
// request USB status (mounted = 1; not mounted = 0)
//
int f_is_mounted() {
	// Check if USB stick mounted
	s_len = Xsprint(s_buf, 0, 's', "/-stat/usbmounted");
	SEND;
	RPOLL
	if (p_status > 0) {
		RECV
		if (strcmp(r_buf, "/-stat/usbmounted") == 0) {
			if ((r_buf[24] + r_buf[25] + r_buf[26] + r_buf[27]) == 1) {
				fUSB_not_Mounted = 0; //USB stick mounted
				if (X32prompt.cc[2] == 0)
					X32prompt.ii[0] = Xmounted.ii;
				return 1;
			} else {
				fUSB_not_Mounted = 1; //USB stick not mounted
				X32prompt.ii[0] = Xnot_mounted.ii;
				return 0;
			}
		}
	}
	return 0;
}

//
// unmount USB stick (USB no more available)
//
int f_umount() {
	// unmount USB drive
	//
	if (!fUSB_not_Mounted) {
		s_len = Xfprint(s_buf, 0, "/-stat/usbmounted", 'i', &zero);
		SEND
		fUSB_not_Mounted = 1;
		X32prompt.ii[0] = Xnot_mounted.ii;
	}
	return 1;
}

//
// stop (current wav play) command
//
int f_stop() {
	// must be able to send 'stop' whatever the state of the system
	s_len = Xfprint(s_buf, 0, "/-stat/tape/state", 'i', &zero);
	SEND
	f_State = STOP;
	return 1;
}

//
// pause (current wav play) command
//
int f_pause() {
	if (f_State == PLAY) {
		s_len = Xfprint(s_buf, 0, "/-stat/tape/state", 'i', &one);
		SEND
		f_State = PAUSE;
	} else {
		printf ("No WAV file playing or selected\n");fflush(stdout);
	}
	return 1;
}

//
// resume (current wav play) command
//
int f_resume() {
	if (f_State == PAUSE) {
		s_len = Xfprint(s_buf, 0, "/-stat/tape/state", 'i', &two);
		SEND
		f_State = PLAY;
	} else {
		printf ("No WAV file playing or selected\n");fflush(stdout);
	}
	return 1;
}

//
// free and init file tree
//
void f_free() {

	//
	// Erase current tree if it exists
	fTree = fTreetop;
	while (fTree) {
		if (fTree->fName)
			free(fTree->fName);
		fTree = fTree->fNext;
		if (fTree)
			free(fTree->fPrev);
	}
	fTreetop = fTree = NULL;
	num_files = 0;
}

//
// delete and rebuild tree of current directory
// returns the number of entries found or a negative number
// of entries if the list somehow was truncated
//
int f_tree() {
	int nFiles = 0;
	int e_end = 0;
	//
	// returns the number of files found, or 0
	//
	f_free();
	//
	// USB stick is mounted - Check number of entries
	s_len = Xsprint(s_buf, 0, 's', "/-usb/dir/maxpos");
	SEND;
	RPOLL
	if (p_status > 0) {
		RECV
		if (strcmp(r_buf, "/-usb/dir/maxpos") == 0) {
			j = 4, k = 24;
			while (j)
				endian.cc[--j] = r_buf[k++];
			nFiles = endian.ii;
		}
	} else {
		printf("Receive error\n");fflush(stdout);
		return (0);
	}
	//
	// List entries/names
	printf("Found %d files or folders\n", nFiles);fflush(stdout);
	if (nFiles > 0) {
		for (i = 1; i <= nFiles; i++) {
			sprintf(tmpstr, "/-usb/dir/%03d/name", i);
			s_len = Xsprint(s_buf, 0, 's', tmpstr);
			SEND;
			RPOLL
			if (p_status > 0) {
				RECV
				if (strcmp(r_buf, tmpstr) == 0) {
					e_end = 0;
					j = 24;
					if (*(r_buf + 24) != 0) {
						if (fTree) {
							fTree->fNext = fTalloc
							fTree->fNext->fPrev = fTree;
							fTree = fTree->fNext;
						} else {
							fTree = fTreetop = fTalloc
							fTree->fPrev = NULL;
						}
						fTree->fNext = NULL;
						fTree->index = i;
						fTree->fType = fParse(r_buf + 24);
						fNameLength = strlen(r_buf + 24);
						fTree->fName = malloc(fNameLength + 1);
						strcpy(fTree->fName, r_buf + 24);
					}
				}
			} else {
				// arbitrarily set number of attempts to 5
				if (e_end > 5) {
					return -i; // early end!
				} else {
					e_end += 1;
					// attempt to recover the missed comm
					i -= 1; // do it again!
				}
			}
		}
	}
	return nFiles;
}

//
// directory listing (2 column display id, type and file names)
//
int f_ls() {
	//
	if (!(f_is_mounted())) {
		printf("No USB stick mounted!\n");fflush(stdout);
		return 1; // do nothing
	}
	fXor = fLpos = 0;
	//
	// USB stick is mounted - Check number of entries
	num_files = f_tree();
	if (num_files < 0) {
		num_files = -num_files;
		printf("/!\\ Truncated list!\n");
	}
	if (num_files) {
		fTree = fTreetop;
		while (fTree) {
			if ((fTree->fType == VOLUME) || (fTree->fType == DIR)
					|| (fTree->fType == PARENT)) {
				printf("%3d-%3s: %s\n", fTree->index, fTypeSTR[fTree->fType],
						fTree->fName);
			} else {
				fXor ^= 1;
				if (fXor) {
					// Print left column
					printf("%3d-%3s: %s", fTree->index, fTypeSTR[fTree->fType],
							fTree->fName);
					fLpos = sizeof("123-123: ") + strlen(fTree->fName);
				} else {
					// Print right column
					while (fLpos < 48) {
						fLpos += 8;
						printf("\t");
					};
					printf("%3d-%3s: %s\n", fTree->index,
							fTypeSTR[fTree->fType], fTree->fName);
				}
			}
			fTree = fTree->fNext;
		}
	}
	if (fXor)
		printf("\n");
	printf("End of listing\n");fflush(stdout);
	return 1;
}

//
// Change directory functions
//
// change directory from id number
//
int f_cd(int fNum) {
	//
	// Search tree for fNum
	fTree = fTreetop;
	while (fTree) {
		if (fTree->index == fNum) {
			if (fTree->fType == DIR || fTree->fType == PARENT) {
				//
				// execute that directory index is equiv to cd to directory
				s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i', &fNum);
				SEND
				fUpdatePath_cd();
				return 1;
			}
		}
		fTree = fTree->fNext;
	}
	printf("Directory not found!\n");fflush(stdout);
	return 1;
}

//
// change directory from file name
//
int f_cdName(char* str) {
	//
	// Search name in tree and act depending on result
	if ((fTree = fFname(str)) != NULL) {
		if (fTree->fType == DIR || fTree->fType == PARENT) {
			//
			// execute that directory index is equiv to cd to directory
			s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i',
					&(fTree->index));
			SEND
			fUpdatePath_cd();
			return 1;
		}
	}
	printf("Directory not found!\n");fflush(stdout);
	return 1;
}

//
// File functions (play, load, etc...)
//
// play WAV file from id number
//
int f_play(int fNum) {
	//
	// Search tree for fNum
	fTree = fTreetop;
	while (fTree) {
		if (fTree->index == fNum) {
			if (fTree->fType == WAV) {
				//
				// select file index is equivalent to play file
				s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i', &fNum);
				SEND
				f_State = PLAY;
				return 1;
			} else {
				if (fTree->fType == NIL) {
					printf("Unknown type, Sure? ");
					if (gets(tmpstr) != NULL) {			// read input line (wait mode)
						if (tmpstr[0] == 'y' || tmpstr[0] == 'Y') {
							//
							// select file index is equivalent to play file
							s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i', &fNum);
							SEND
							f_State = PLAY;
							return 1;
						}
					}
				}
			}
		}
		fTree = fTree->fNext;
	}
	printf("File not found!\n");fflush(stdout);
	return 1;
}
//
// play WAV file from file name
//
int f_playName(char* str) {
	//
	// Search name in tree and act depending on result
	if ((fTree = fFname(str)) != NULL) {
		if (fTree->fType == WAV) {
			//
			// select file index is equivalent to play file
			s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i', &(fTree->index));
			SEND
			f_State = PLAY;
			return 1;
		} else {
			if (fTree->fType == NIL) {
				printf("Unknown type, Sure? ");
				if (gets(tmpstr) != NULL) {			// read input line (wait mode)
					if (tmpstr[0] == 'y' || tmpstr[0] == 'Y') {
						//
						// select file index is equivalent to play file
						s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i', &(fTree->index));
						SEND
						f_State = PLAY;
						return 1;
					}
				}
			}
		}
	}
	printf("File not found!\n");fflush(stdout);
	return 1;
}

//
// Load/Run file functions
//
// load or run command from file id number
//
int f_load(int fNum) {
	//
	// Search tree for fNum
	fTree = fTreetop;
	while (fTree) {
		if (fTree->index == fNum) {
			if ((fTree->fType == SCENE) || (fTree->fType == SNIPPET)
					|| (fTree->fType == EFFECTS) || (fTree->fType == ROUT)
					|| (fTree->fType == CHAN)) {
				//
				// select file index is equivalent to load file
				s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i', &fNum);
				SEND
				return 1;
			}
		}
		fTree = fTree->fNext;
	}
	printf("File not found!\n");fflush(stdout);
	return 1;
}
//
// load or run command from file file name
//
int f_loadName(char* str) {
	//
	// Search name in tree and act depending on result
	if ((fTree = fFname(str)) != NULL) {
		if ((fTree->fType == SCENE) || (fTree->fType == SNIPPET)
				|| (fTree->fType == EFFECTS) || (fTree->fType == ROUT)
				|| (fTree->fType == CHAN)) {
			//
			// select file index is equivalent to load file
			s_len = Xfprint(s_buf, 0, "/-action/recselect", 'i',
					&(fTree->index));
			SEND
			return 1;
		}
	}
	printf("File not found!\n");fflush(stdout);
	return 1;
}
//
// display help
//
int f_help() {
	printf("  ls                  List directory contents (with id and type)\n");
	printf("  dir                 List directory contents (with id and type)\n");
	printf("  cd <id> | <name>    Change directory (prompt is updated)\n");
	printf("  load <id> | <name>  Load or Run file (scene, snippet, etc.)\n");
	printf("  run <id> | <name>   Load or Run file (scene, snippet, etc.)\n");
	printf("  umount              Unmount the USB drive (no longer accessible)\n\n");
	printf("  play <id> | <name>  Play WAV file\n");
	printf("  stop                Stops a currently playing wav\n");
	printf("  pause               Pauses a wav file currently playing\n");
	printf("  resume              Resumes playing the current wav file\n");
	printf("  exit | quit         Exists program\n\n");
	fflush(stdout);
	return 1;
}
//
// X32USB : An X32 shell for remote managing USB files
//
int main(int argc, char **argv) {
	int keep_on;
	char ch_opt;
	//
	// initialize communication with X32 server at IP ip and PORT port
	//	set a default value for server[]; change to match your X32 desk
	strcpy(Xip_str, "192.168.1.62");
	strcpy(Xport_str, "10023");
	//
	// Manage arguments
	s_delay = 0;
	while ((ch_opt = getopt(argc, argv, "i:d:v:t:h")) != (char)-1) {
		switch (ch_opt) {
		case 'i':
			strcpy(Xip_str, optarg);
			break;
		case 'd':
			sscanf(optarg, "%d", &X32debug);
			break;
		case 'v':
			sscanf(optarg, "%d", &X32verbose);
			break;
		case 't':
			sscanf(optarg, "%d", &s_delay);
			break;
		default:
		case 'h':
			printf("usage: X32USB [-i X32 console ipv4 address]\n");
			printf("              [-d 0/1, [0], debug option]\n");
			printf("              [-v 0/1  [1], verbose option]\n");
			printf("              [-t <delay>, delay in ms between commands]\n");
			printf("                   default IP: 192.168.0.64\n\n");
			printf("Launch shell to accept the following commands applied to the X32 USB drive:\n");
			printf("  ls                  List directory contents (with id and type)\n");
			printf("  dir                 List directory contents (with id and type)\n");
			printf("  cd <id> | <name>    Change directory (prompt is updated)\n");
			printf("  load <id> | <name>  Load or Run file (scene, snippet, etc.)\n");
			printf("  run <id> | <name>   Load or Run file (scene, snippet, etc.)\n");
			printf("  umount              Unmount the USB drive (no longer accessible)\n\n");
			printf("  play <id> | <name>  Play WAV file\n");
			printf("  stop                Stops a currently playing wav\n");
			printf("  pause               Pauses a wav file currently playing\n");
			printf("  resume              Resumes playing the current wav file\n");
			printf("  exit | quit         Exists program\n");
			fflush(stdout);
			return (0);
			break;
		}
	}
#ifdef __WIN32__
	//
	//Initialize winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
#endif
	//
	// Load the X32 address we connect to; we're a client to X32, keep it simple.
	// Create the UDP socket
	if ((Xfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("failed to create X32 socket");
		exit(EXIT_FAILURE);
	}
	//
	// Construct the server sockaddr_in structure
	memset(&Xip, 0, sizeof(Xip));				// Clear struct
	Xip.sin_family = AF_INET;					// Internet/IP
	Xip.sin_addr.s_addr = inet_addr(Xip_str);	// IP address
	Xip.sin_port = htons(atoi(Xport_str));		// server port
	//
	//register for receiving X32 console updates
	// Non blocking mode
	timeout.tv_sec = 0;
	timeout.tv_usec = 500000; //Set timeout for non blocking recvfrom(): 500ms
	//
	// All done.
	printf(" X32USB - v0.3 - (c)2015-17 Patrick-Gilles Maillot\n\n");
	//
	// Let's send and receive messages
	// Establish logical connection with X32 server
	keep_on = 1;
	printf("Connecting to X32.");
	s_len = Xsprint(s_buf, 0, 's', "/info");
	while (keep_on) {
		SEND // command /info sent; read data if available
		RPOLL // poll for data in
		if (p_status < 0) {
			printf("Polling for response from X32 failed\n");
			return 1;		// exit on receive error
		} else if (p_status > 0) {
			RECV // We have received data - process it!
			if (strcmp(r_buf, "/info") == 0)
				break;	// Connected!
		}				// ... else timeout
		printf(".");
	}
	printf(" Done!\n");fflush(stdout);

	//
	// We're connected! Prompt depends on USB mounted or not
	timeout.tv_sec = 0;
	timeout.tv_usec = 50000; //Set timeout for non blocking recvfrom(): 50ms
	keep_on = fSetPrompt();
	//
	// "infinite" loop for shell commands
	while (keep_on) {
		printf("%s ", X32prompt.cc);		// display prompt
		if (gets(tmpstr) != NULL) {			// read input line (wait mode)
			//
			// Parse commands
			if (strncmp(tmpstr, "ls", 2) == 0)
				keep_on = f_ls();						// directory list command
			else if (strncmp(tmpstr, "dir", 3) == 0)
				keep_on = 0;							// directory list command
			else if (strncmp(tmpstr, "exit", 4) == 0)
				keep_on = 0;							// exit command
			else if (strncmp(tmpstr, "quit", 4) == 0)
				keep_on = 0;							// exit command
			else if (strncmp(tmpstr, "umount", 6) == 0)
				keep_on = f_umount();					// unmount stick command
			else if (strncmp(tmpstr, "stop", 4) == 0)
				keep_on = f_stop();						// stop (current wav play) command
			else if (strncmp(tmpstr, "pause", 5) == 0)
				keep_on = f_pause(); 					// pause (current wav play) command
			else if (strncmp(tmpstr, "resume", 6) == 0)
				keep_on = f_resume(); 					// resume (current wav play) command
			else if (strncmp(tmpstr, "cd", 2) == 0) 	// change directory commands
				if (sscanf(tmpstr + 2, "%d", &fNum) == 1)
					keep_on = f_cd(fNum);
				else
					keep_on = f_cdName(tmpstr + 2);
			else if (strncmp(tmpstr, "play", 4) == 0)	// play USB wav file commands
				if (sscanf(tmpstr + 4, "%d", &fNum) == 1)
					keep_on = f_play(fNum);
				else
					keep_on = f_playName(tmpstr + 4);
			else if (strncmp(tmpstr, "load", 4) == 0) 	// load file commands
				if (sscanf(tmpstr + 4, "%d", &fNum) == 1)
					keep_on = f_load(fNum);
				else
					keep_on = f_loadName(tmpstr + 4);
			else if (strncmp(tmpstr, "run", 3) == 0) 	// load file commands
				if (sscanf(tmpstr + 3, "%d", &fNum) == 1)
					keep_on = f_load(fNum);
				else
					keep_on = f_loadName(tmpstr + 4);
			else if (strncmp(tmpstr, "help", 4) == 0)
				keep_on = f_help();
			else
				keep_on = fSetPrompt();					// set/update default prompt
		} else {
			keep_on = 0;
			printf("command read error\n"); fflush(stdout);
		}
	}
	close(Xfd);
	//
	// Ideally, release memory.
	f_free();
	return 0;
}
