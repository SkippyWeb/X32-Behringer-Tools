/*
 * X32PrefStat.h
 *
 *  Created on: 4 févr. 2015
 *      Author: patrick
 */

#ifndef X32PREFSTAT_H_
#define X32PREFSTAT_H_

#define X32NAME 23			// the position/index of /-prefs/name

X32command Xprefs[] = {
		{"/-prefs",							{PREFS}, F_FND, {0}, NULL},
		{"/-prefs/style",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/bright",				{F32}, F_XET, {0}, NULL},
		{"/-prefs/lcdcont",				{F32}, F_XET, {0}, NULL},
		{"/-prefs/ledbright",			{F32}, F_XET, {0}, NULL},
		{"/-prefs/lamp",				{F32}, F_XET, {0}, NULL},
		{"/-prefs/lampon",				{E32}, F_XET, {0}, OffOn},
		{"/-prefs/clockrate",			{E32}, F_XET, {0}, PRrate},
		{"/-prefs/clocksource",			{E32}, F_XET, {0}, Psource},
		{"/-prefs/confirm_general",		{E32}, F_XET, {0}, OffOn},
		{"/-prefs/confirm_overwrite",	{E32}, F_XET, {0}, OffOn},
		{"/-prefs/confirm_sceneload",	{E32}, F_XET, {0}, OffOn},
		{"/-prefs/viewrtn",				{E32}, F_XET, {0}, OffOn},
		{"/-prefs/selfollowsbank",		{E32}, F_XET, {0}, OffOn},
		{"/-prefs/scene_advance",		{E32}, F_XET, {0}, OffOn},
		{"/-prefs/safe_masterlevels",	{E32}, F_XET, {0}, OffOn},
		{"/-prefs/haflags",				{P32}, F_XET, {0}, NULL},
		{"/-prefs/autosel",				{E32}, F_XET, {0}, OffOn},
		{"/-prefs/show_control",		{E32}, F_XET, {0}, PSCont},
		{"/-prefs/clockmode",			{E32}, F_XET, {0}, Pclkmod},
		{"/-prefs/hardmute",			{E32}, F_XET, {0}, OffOn},
		{"/-prefs/dcamute",				{E32}, F_XET, {0}, OffOn},
		{"/-prefs/invertmutes",			{E32}, F_XET, {0}, Pinvmut},
		{"/-prefs/name",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/rec_control",			{E32}, F_XET, {0}, Purrctl},

		{"/-prefs/remote",					{PIR}, F_FND, {0}, NULL},
		{"/-prefs/remote/enable",		{E32}, F_XET, {0}, OffOn},
		{"/-prefs/remote/protocol",		{E32}, F_XET, {0}, PRpro},
		{"/-prefs/remote/port",			{E32}, F_XET, {0}, PRport},
		{"/-prefs/remote/ioenable",		{P32}, F_XET, {0}, NULL},

		{"/-prefs/iQ",						{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/01",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/01/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/01/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/01/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/02",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/02/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/02/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/02/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/03",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/03/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/03/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/03/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/04",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/04/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/04/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/04/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/05",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/05/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/05/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/05/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/06",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/06/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/06/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/06/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/07",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/07/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/07/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/07/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/08",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/08/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/08/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/08/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/09",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/09/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/09/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/09/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/10",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/10/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/10/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/10/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/11",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/11/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/11/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/11/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/12",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/12/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/12/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/12/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/13",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/13/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/13/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/13/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/14",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/14/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/14/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/14/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/15",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/15/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/15/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/15/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/iQ/16",					{PIQ}, F_FND, {0}, NULL},
		{"/-prefs/iQ/16/iQmodel",		{E32}, F_XET, {0}, XiQspk},
		{"/-prefs/iQ/16/IQeqset",		{E32}, F_XET, {0}, XiQeq},
		{"/-prefs/iQ/16/IQsound",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/card",					{PCARD}, F_FND, {0}, NULL},
		{"/-prefs/card/UFifc",			{E32}, F_XET, {0}, Pctype},
		{"/-prefs/card/UFmode",			{E32}, F_XET, {0}, Pufmode},
		{"/-prefs/card/USBmode",		{E32}, F_XET, {0}, Pusbmod},
		{"/-prefs/card/ADATwc",			{E32}, F_XET, {0}, Pcaw},
		{"/-prefs/card/ADATsync",		{E32}, F_XET, {0}, Pcas},
		{"/-prefs/card/MADImode",		{E32}, F_XET, {0}, Pmdmode},
		{"/-prefs/card/MADIin",			{E32}, F_XET, {0}, Pcmadi},
		{"/-prefs/card/MADIout",		{E32}, F_XET, {0}, Pcmado},
		{"/-prefs/card/MADIsrc",		{E32}, F_XET, {0}, Pmadsrc},
		{"/-prefs/card/URECtracks",		{E32}, F_XET, {0}, Purectk},
		{"/-prefs/card/URECplayb",		{E32}, F_XET, {0}, Purplbk},
		{"/-prefs/card/URECrout",		{E32}, F_XET, {0}, Purerpa},
		{"/-prefs/card/URECsdsel",		{E32}, F_XET, {0}, Pursdsl},

		{"/-prefs/rta",						{PRTA}, F_FND, {0}, NULL},
		{"/-prefs/rta/visibility",		{E32}, F_XET, {0}, Prtavis},
		{"/-prefs/rta/gain",			{F32}, F_XET, {0}, NULL},
		{"/-prefs/rta/autogain",		{E32}, F_XET, {0}, OffOn},
		{"/-prefs/rta/source",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/rta/pos",				{E32}, F_XET, {0}, PRpos},
		{"/-prefs/rta/mode",			{E32}, F_XET, {0}, PRmode},
		{"/-prefs/rta/options",			{P32}, F_XET, {0}, NULL},
		{"/-prefs/rta/det",				{E32}, F_XET, {0}, PRdet},
		{"/-prefs/rta/decay",			{F32}, F_XET, {0}, NULL},
		{"/-prefs/rta/peakhold",		{E32}, F_XET, {0}, Prtaph},

		{"/-prefs/ip",						{PIP}, F_FND, {0}, NULL},
		{"/-prefs/ip/dhcp",				{E32}, F_XET, {0}, OffOn},

		{"/-prefs/ip/addr",					{PADDR}, F_FND, {0}, NULL},
		{"/-prefs/ip/addr/0",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/addr/1",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/addr/2",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/addr/3",			{I32}, F_XET, {0}, NULL},


		{"/-prefs/ip/mask",					{PADDR}, F_FND, {0}, NULL},
		{"/-prefs/ip/mask/0",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/mask/1",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/mask/2",			{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/mask/3",			{I32}, F_XET, {0}, NULL},


		{"/-prefs/ip/gateway",				{PADDR}, F_FND, {0}, NULL},
		{"/-prefs/ip/gateway/0",		{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/gateway/1",		{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/gateway/2",		{I32}, F_XET, {0}, NULL},
		{"/-prefs/ip/gateway/3",		{I32}, F_XET, {0}, NULL},

		{"/-prefs/key",						{PKEY}, F_FND, {0}, NULL},
		{"/-prefs/key/layout",			{E32}, F_XET, {0}, NULL},
		{"/-prefs/key/00",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/01",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/02",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/03",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/04",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/05",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/06",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/07",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/08",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/09",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/10",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/11",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/12",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/13",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/14",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/15",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/16",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/17",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/18",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/19",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/20",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/21",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/22",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/23",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/24",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/25",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/26",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/27",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/28",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/29",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/30",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/31",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/32",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/33",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/34",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/35",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/36",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/37",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/38",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/39",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/40",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/41",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/42",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/43",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/44",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/45",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/46",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/47",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/48",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/49",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/50",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/51",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/52",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/53",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/54",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/55",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/56",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/57",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/58",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/59",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/60",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/61",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/62",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/63",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/64",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/65",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/66",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/67",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/68",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/69",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/70",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/71",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/72",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/73",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/74",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/75",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/76",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/77",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/78",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/79",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/80",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/81",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/82",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/83",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/84",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/85",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/86",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/87",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/88",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/89",				{S32}, F_XET, {0}, NULL},

		{"/-prefs/key/90",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/91",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/92",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/93",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/94",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/95",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/96",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/97",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/98",				{S32}, F_XET, {0}, NULL},
		{"/-prefs/key/99",				{S32}, F_XET, {0}, NULL},
};
int Xprefs_max = sizeof(Xprefs) / sizeof(X32command);


X32command Xstat[] = {
		{"/-stat",						{STAT}, F_FND, {0}, NULL},
		{"/-stat/selidx",			{E32}, F_XET, {0}, Sselidx},
		{"/-stat/chfaderbank",		{I32}, F_XET, {0}, NULL},
		{"/-stat/grpfaderbank",		{I32}, F_XET, {0}, NULL},
		{"/-stat/sendsonfader",		{E32}, F_XET, {0}, OffOn},
		{"/-stat/bussendbank",		{I32}, F_XET, {0}, NULL},
		{"/-stat/eqband",			{I32}, F_XET, {0}, NULL},
		{"/-stat/solo",				{E32}, F_XET, {0}, OffOn},
		{"/-stat/keysolo",			{E32}, F_XET, {0}, OffOn},
		{"/-stat/userbank",			{I32}, F_XET, {0}, NULL},
		{"/-stat/autosave",			{E32}, F_XET, {0}, OffOn},
		{"/-stat/lock",				{I32}, F_XET, {0}, NULL},
		{"/-stat/usbmounted",		{E32}, F_XET, {0}, OffOn},
		{"/-stat/remote",			{E32}, F_XET, {0}, OffOn},
		{"/-stat/rtamodeeq",		{E32}, F_XET, {0}, PRmode},
		{"/-stat/rtamodegeq",		{E32}, F_XET, {0}, PRmode},
		{"/-stat/rtaeqpre",			{E32}, F_XET, {0}, OffOn},
		{"/-stat/rtageqpost",		{E32}, F_XET, {0}, OffOn},
		{"/-stat/rtasource",		{I32}, F_XET, {0}, NULL},
		{"/-stat/xcardtype",		{I32}, F_XET, {0}, NULL},
		{"/-stat/xcardsync",		{E32}, F_XET, {0}, OffOn},
		{"/-stat/geqonfdr",			{E32}, F_XET, {0}, OffOn},
		{"/-stat/geqpos",			{I32}, F_XET, {0}, NULL},
		{"/-stat/dcaspill",			{I32}, F_XET, {0}, NULL},

		{"/-stat/screen",					{SSCREEN}, F_FND, {0}, NULL},
		{"/-stat/screen/screen",		{E32}, F_XET, {0}, Sscrn},
		{"/-stat/screen/mutegrp",		{E32}, F_XET, {0}, OffOn},
		{"/-stat/screen/utils",			{E32}, F_XET, {0}, OffOn},
//
		{"/-stat/screen/CHAN",				{SCHA}, F_FND, {0}, NULL},
		{"/-stat/screen/CHAN/page",		{E32}, F_XET, {0}, Schal},

		{"/-stat/screen/METER",				{SMET}, F_FND, {0}, NULL},
		{"/-stat/screen/METER/page",	{E32}, F_XET, {0}, Smetl},

		{"/-stat/screen/ROUTE",				{SROU}, F_FND, {0}, NULL},
		{"/-stat/screen/ROUTE/page",	{E32}, F_XET, {0}, Sroul},

		{"/-stat/screen/SETUP",				{SSET}, F_FND, {0}, NULL},
		{"/-stat/screen/SETUP/page",	{E32}, F_XET, {0}, Ssetl},

		{"/-stat/screen/LIB",				{SLIB}, F_FND, {0}, NULL},
		{"/-stat/screen/LIB/page",		{E32}, F_XET, {0}, Slibl},

		{"/-stat/screen/FX",				{SFX}, F_FND, {0}, NULL},
		{"/-stat/screen/FX/page",		{E32}, F_XET, {0}, Sfxl},

		{"/-stat/screen/MON",				{SMON}, F_FND, {0}, NULL},
		{"/-stat/screen/MON/page",		{E32}, F_XET, {0}, Smonl},

		{"/-stat/screen/USB",				{SUSB}, F_FND, {0}, NULL},
		{"/-stat/screen/USB/page",		{E32}, F_XET, {0}, Susbl},

		{"/-stat/screen/SCENE",			{SSCE}, F_FND, {0}, NULL},
		{"/-stat/screen/SCENE/page",	{E32}, F_XET, {0}, Sscel},

		{"/-stat/screen/ASSIGN",			{SASS}, F_FND, {0}, NULL},
		{"/-stat/screen/ASSIGN/page",	{E32}, F_XET, {0}, Sassl},

		{"/-stat/solosw",			{SSOLOSW}, F_FND, {80}, NULL},
		{"/-stat/solosw/01",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/02",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/03",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/04",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/05",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/06",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/07",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/08",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/09",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/10",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/11",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/12",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/13",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/14",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/15",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/16",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/17",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/18",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/19",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/20",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/21",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/22",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/23",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/24",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/25",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/26",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/27",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/28",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/29",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/30",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/31",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/32",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/33",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/34",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/35",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/36",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/37",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/38",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/39",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/40",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/41",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/42",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/43",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/44",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/45",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/46",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/47",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/48",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/49",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/50",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/51",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/52",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/53",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/54",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/55",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/56",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/57",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/58",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/59",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/60",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/61",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/62",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/63",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/64",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/65",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/66",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/67",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/68",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/69",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/70",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/71",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/72",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/73",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/74",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/75",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/76",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/77",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/78",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/79",	{E32}, F_XET, {0}, OffOn},
		{"/-stat/solosw/80",	{E32}, F_XET, {0}, OffOn},

		{"/-stat/aes50",				{SAES}, F_FND, {0}, NULL},
		{"/-stat/aes50/A",			{S32}, F_XET, {0}, NULL},
		{"/-stat/aes50/B",			{S32}, F_XET, {0}, NULL},
		{"/-stat/aes50/state",		{P32}, F_XET, {0}, NULL},

		{"/-stat/tape",					{STAPE}, F_FND, {0}, NULL},
		{"/-stat/tape/state",		{E32}, F_XET, {0}, Stapl},
		{"/-stat/tape/file",		{S32}, F_XET, {0}, NULL},
		{"/-stat/tape/etime",		{E32}, F_XET, {0}, NULL},
		{"/-stat/tape/rtime",		{E32}, F_XET, {0}, NULL},

		{"/-stat/osc",					{SOSC}, F_FND, {0}, NULL},
		{"/-stat/osc/on",			{E32}, F_XET, {0}, OffOn},

		{"/-stat/talk",					{STALK}, F_FND, {0}, NULL},
		{"/-stat/talk/A",			{E32}, F_XET, {0}, OffOn},
		{"/-stat/talk/B",			{E32}, F_XET, {0}, OffOn},

		{"/-stat/urec",					{E32}, F_XET, {0}, NULL},
		{"/-stat/urec/state",		{E32}, F_XET, {0}, NULL},
		{"/-stat/urec/etime",		{E32}, F_XET, {0}, NULL},
		{"/-stat/urec/rtime",		{E32}, F_XET, {0}, NULL},

};
int 	Xstat_max = sizeof(Xstat) / sizeof(X32command);



X32command Xaction[] = {
		{"/-action",						{ACTION}, F_FND, {0}, NULL},
		{"/-action/setip",			{I32}, F_XET, {0}, NULL},
		{"/-action/setclock",		{S32}, F_XET, {0}, NULL},
		{"/-action/initall",			{I32}, F_XET, {0}, NULL},
		{"/-action/initlib",			{I32}, F_XET, {0}, NULL},
		{"/-action/initshow",		{I32}, F_XET, {0}, NULL},
		{"/-action/savestate",		{I32}, F_XET, {0}, NULL},
		{"/-action/undopt",			{I32}, F_XET, {0}, NULL},
		{"/-action/doundo",			{I32}, F_XET, {0}, NULL},
		{"/-action/platrack",		{I32}, F_XET, {0}, NULL},
		{"/-action/newscreen",		{I32}, F_XET, {0}, NULL},
		{"/-action/clearsolo",		{I32}, F_XET, {0}, NULL},
		{"/-action/setprebus",		{I32}, F_XET, {0}, NULL},
		{"/-action/setsrate",		{I32}, F_XET, {0}, NULL},
		{"/-action/setrtasrc",		{I32}, F_XET, {0}, NULL},
		{"/-action/newscreen",		{I32}, F_XET, {0}, NULL},
		{"/-action/recselect",		{I32}, F_XET, {0}, NULL},
		{"/-action/gocue",			{I32}, F_XET, {0}, NULL},
		{"/-action/goscene",			{I32}, F_XET, {0}, NULL},
		{"/-action/undopt",			{I32}, F_XET, {0}, NULL},
		{"/-action/gosnippet",		{I32}, F_XET, {0}, NULL},
		{"/-action/selsession",		{I32}, F_XET, {0}, NULL},
		{"/-action/delsession",		{I32}, F_XET, {0}, NULL},
		{"/-action/selmarker",		{I32}, F_XET, {0}, NULL},
		{"/-action/delmarker",		{I32}, F_XET, {0}, NULL},
		{"/-action/savemarker",		{I32}, F_XET, {0}, NULL},
		{"/-action/addmarker",		{I32}, F_XET, {0}, NULL},
		{"/-action/selposition",		{I32}, F_XET, {0}, NULL},
		{"/-action/clearalert",		{I32}, F_XET, {0}, NULL},
		{"/-action/formatcard",		{I32}, F_XET, {0}, NULL},

};
int 	Xaction_max = sizeof(Xaction) / sizeof(X32command);


X32command Xurec[] = {
		{"/-urec",					{UREC}, F_FND, {0}, NULL},
		{"/-urec/sessionmax",	{I32}, F_XET, {0}, NULL},
		{"/-urec/markermax",	{I32}, F_XET, {0}, NULL},
		{"/-urec/sessionlen",	{I32}, F_XET, {0}, NULL},
		{"/-urec/sessionpos",	{I32}, F_XET, {0}, NULL},
		{"/-urec/markerpos",	{I32}, F_XET, {0}, NULL},
		{"/-urec/batterystate",	{E32}, F_XET, {0}, Ubat},
		{"/-urec/srate",		{I32}, F_XET, {0}, NULL},
		{"/-urec/tracks",		{I32}, F_XET, {0}, NULL},
		{"/-urec/sessionspan",	{I32}, F_XET, {0}, NULL},
		{"/-urec/sessionoffs",	{I32}, F_XET, {0}, NULL},
		{"/-urec/sd1state",		{E32}, F_XET, {0}, Usdc},
		{"/-urec/sd2state",		{E32}, F_XET, {0}, Usdc},
		{"/-urec/sd1info",		{S32}, F_XET, {0}, NULL},
		{"/-urec/sd2info",		{S32}, F_XET, {0}, NULL},
		{"/-urec/errormessage",	{S32}, F_XET, {0}, NULL},
		{"/-urec/errorcode",	{I32}, F_XET, {0}, NULL},

		{"/-urec/session",					{S32}, F_FND, {0}, NULL},
		{"/-urec/session/001/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/002/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/003/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/004/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/005/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/006/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/007/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/008/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/009/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/010/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/011/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/012/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/013/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/014/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/015/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/016/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/017/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/018/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/019/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/020/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/021/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/022/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/023/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/024/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/025/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/026/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/027/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/028/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/029/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/030/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/031/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/032/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/033/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/034/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/035/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/036/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/037/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/038/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/039/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/040/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/041/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/042/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/043/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/044/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/045/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/046/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/047/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/048/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/049/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/050/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/051/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/052/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/053/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/054/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/055/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/056/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/057/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/058/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/059/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/060/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/061/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/062/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/063/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/064/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/065/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/066/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/067/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/068/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/069/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/070/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/071/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/072/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/073/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/074/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/075/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/076/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/077/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/078/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/079/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/080/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/081/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/082/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/083/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/084/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/085/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/086/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/087/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/088/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/089/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/090/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/091/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/092/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/093/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/094/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/095/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/096/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/097/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/098/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/099/name",		{S32}, F_XET, {0}, NULL},
		{"/-urec/session/100/name",		{S32}, F_XET, {0}, NULL},

		{"/-urec/marker",					{I32}, F_FND, {0}, NULL},
		{"/-urec/marker/001/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/002/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/003/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/004/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/005/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/006/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/007/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/008/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/009/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/010/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/011/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/012/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/013/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/014/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/015/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/016/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/017/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/018/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/019/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/020/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/021/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/022/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/023/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/024/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/025/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/026/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/027/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/028/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/029/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/030/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/031/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/032/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/033/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/034/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/035/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/036/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/037/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/038/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/039/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/040/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/041/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/042/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/043/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/044/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/045/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/046/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/047/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/048/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/049/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/050/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/051/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/052/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/053/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/054/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/055/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/056/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/057/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/058/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/059/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/060/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/061/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/062/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/063/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/064/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/065/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/066/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/067/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/068/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/069/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/070/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/071/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/072/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/073/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/074/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/075/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/076/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/077/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/078/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/079/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/080/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/081/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/082/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/083/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/084/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/085/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/086/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/087/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/088/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/089/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/090/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/091/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/092/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/093/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/094/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/095/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/096/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/097/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/098/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/099/time",		{I32}, F_XET, {0}, NULL},
		{"/-urec/marker/100/time",		{I32}, F_XET, {0}, NULL},

}; 
int 	Xurec_max = sizeof(Xurec) / sizeof(X32command);


#endif /* X32PREFSTAT_H_ */