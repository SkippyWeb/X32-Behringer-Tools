/*
 * X32Mtx.h
 *
 *  Created on: 4 févr. 2015
 *      Author: patrick
 */

#ifndef X32MTX_H_
#define X32MTX_H_

X32command Xmtx01[] = {
		{"/mtx",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/01",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/01/config",						{BSCO}, F_FND, {0}, NULL},
		{"/mtx/01/config/name",				{S32}, F_XET, {0}, NULL},
		{"/mtx/01/config/icon",				{I32}, F_XET, {0}, NULL},
		{"/mtx/01/config/color",			{E32}, F_XET, {0}, Xcolors},
		{"/mtx/01/preamp",						{MXPR}, F_FND, {0}, NULL},
		{"/mtx/01/preamp/invert",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/dyn",							{MXDY}, F_FND, {0}, NULL},
		{"/mtx/01/dyn/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/dyn/mode",				{E32}, F_XET, {0}, Xdymode},
		{"/mtx/01/dyn/det",					{E32}, F_XET, {0}, Xdydet},
		{"/mtx/01/dyn/env",					{E32}, F_XET, {0}, Xdyenv},
		{"/mtx/01/dyn/thr",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/ratio",				{E32}, F_XET, {0}, Xdyrat},
		{"/mtx/01/dyn/knee",				{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/mgain",				{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/attack",				{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/hold",				{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/release",				{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/pos",					{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/01/dyn/mix",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/dyn/auto",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/dyn/filter",					{CHDF}, F_FND, {0}, NULL},
		{"/mtx/01/dyn/filter/on",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/dyn/filter/type",			{E32}, F_XET, {0}, Xdyftyp},
		{"/mtx/01/dyn/filter/f",			{F32}, F_XET, {0}, NULL},
		{"/mtx/01/insert",						{CHIN}, F_FND, {0}, NULL},
		{"/mtx/01/insert/on",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/insert/pos",				{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/01/insert/sel",				{E32}, F_XET, {0}, Xisel},
		{"/mtx/01/eq",							{OFFON}, F_FND, {1}, NULL},
		{"/mtx/01/eq/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/eq/1",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/01/eq/1/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/01/eq/1/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/1/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/1/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/2",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/01/eq/2/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/01/eq/2/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/2/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/2/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/3",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/01/eq/3/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/01/eq/3/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/3/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/3/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/4",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/01/eq/4/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/01/eq/4/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/4/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/4/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/5",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/01/eq/5/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/01/eq/5/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/5/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/5/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/6",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/01/eq/6/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/01/eq/6/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/6/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/eq/6/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/01/mix",							{CHME}, F_FND, {0}, NULL},
		{"/mtx/01/mix/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/01/mix/fader",				{F32}, F_XET, {0}, NULL},
		{"/mtx/01/grp",							{CHGRP}, F_FND, {0}, NULL},
		{"/mtx/01/grp/dca",					{P32}, F_XET, {0}, NULL},
		{"/mtx/01/grp/mute",				{P32}, F_XET, {0}, NULL},
};
int Xmtx01_max = sizeof(Xmtx01) / sizeof(X32command);


X32command Xmtx02[] = {
		{"/mtx",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/02",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/02/config",						{BSCO}, F_FND, {0}, NULL},
		{"/mtx/02/config/name",				{S32}, F_XET, {0}, NULL},
		{"/mtx/02/config/icon",				{I32}, F_XET, {0}, NULL},
		{"/mtx/02/config/color",			{E32}, F_XET, {0}, Xcolors},
		{"/mtx/02/preamp",						{MXPR}, F_FND, {0}, NULL},
		{"/mtx/02/preamp/invert",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/dyn",							{MXDY}, F_FND, {0}, NULL},
		{"/mtx/02/dyn/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/dyn/mode",				{E32}, F_XET, {0}, Xdymode},
		{"/mtx/02/dyn/det",					{E32}, F_XET, {0}, Xdydet},
		{"/mtx/02/dyn/env",					{E32}, F_XET, {0}, Xdyenv},
		{"/mtx/02/dyn/thr",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/ratio",				{E32}, F_XET, {0}, Xdyrat},
		{"/mtx/02/dyn/knee",				{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/mgain",				{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/attack",				{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/hold",				{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/release",				{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/pos",					{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/02/dyn/mix",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/dyn/auto",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/dyn/filter",					{CHDF}, F_FND, {0}, NULL},
		{"/mtx/02/dyn/filter/on",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/dyn/filter/type",			{E32}, F_XET, {0}, Xdyftyp},
		{"/mtx/02/dyn/filter/f",			{F32}, F_XET, {0}, NULL},
		{"/mtx/02/insert",						{CHIN}, F_FND, {0}, NULL},
		{"/mtx/02/insert/on",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/insert/pos",				{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/02/insert/sel",				{E32}, F_XET, {0}, Xisel},
		{"/mtx/02/eq",							{OFFON}, F_FND, {1}, NULL},
		{"/mtx/02/eq/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/eq/1",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/02/eq/1/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/02/eq/1/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/1/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/1/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/2",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/02/eq/2/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/02/eq/2/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/2/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/2/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/3",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/02/eq/3/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/02/eq/3/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/3/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/3/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/4",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/02/eq/4/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/02/eq/4/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/4/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/4/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/5",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/02/eq/5/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/02/eq/5/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/5/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/5/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/6",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/02/eq/6/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/02/eq/6/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/6/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/eq/6/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/02/mix",							{CHME}, F_FND, {0}, NULL},
		{"/mtx/02/mix/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/02/mix/fader",				{F32}, F_XET, {0}, NULL},
		{"/mtx/02/grp",							{CHGRP}, F_FND, {0}, NULL},
		{"/mtx/02/grp/dca",					{P32}, F_XET, {0}, NULL},
		{"/mtx/02/grp/mute",				{P32}, F_XET, {0}, NULL},
};
int Xmtx02_max = sizeof(Xmtx02) / sizeof(X32command);


X32command Xmtx03[] = {
		{"/mtx",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/03",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/03/config",						{BSCO}, F_FND, {0}, NULL},
		{"/mtx/03/config/name",				{S32}, F_XET, {0}, NULL},
		{"/mtx/03/config/icon",				{I32}, F_XET, {0}, NULL},
		{"/mtx/03/config/color",			{E32}, F_XET, {0}, Xcolors},
		{"/mtx/03/preamp",						{MXPR}, F_FND, {0}, NULL},
		{"/mtx/03/preamp/invert",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/dyn",							{MXDY}, F_FND, {0}, NULL},
		{"/mtx/03/dyn/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/dyn/mode",				{E32}, F_XET, {0}, Xdymode},
		{"/mtx/03/dyn/det",					{E32}, F_XET, {0}, Xdydet},
		{"/mtx/03/dyn/env",					{E32}, F_XET, {0}, Xdyenv},
		{"/mtx/03/dyn/thr",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/ratio",				{E32}, F_XET, {0}, Xdyrat},
		{"/mtx/03/dyn/knee",				{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/mgain",				{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/attack",				{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/hold",				{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/release",				{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/pos",					{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/03/dyn/mix",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/dyn/auto",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/dyn/filter",					{CHDF}, F_FND, {0}, NULL},
		{"/mtx/03/dyn/filter/on",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/dyn/filter/type",			{E32}, F_XET, {0}, Xdyftyp},
		{"/mtx/03/dyn/filter/f",			{F32}, F_XET, {0}, NULL},
		{"/mtx/03/insert",						{CHIN}, F_FND, {0}, NULL},
		{"/mtx/03/insert/on",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/insert/pos",				{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/03/insert/sel",				{E32}, F_XET, {0}, Xisel},
		{"/mtx/03/eq",							{OFFON}, F_FND, {1}, NULL},
		{"/mtx/03/eq/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/eq/1",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/03/eq/1/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/03/eq/1/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/1/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/1/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/2",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/03/eq/2/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/03/eq/2/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/2/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/2/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/3",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/03/eq/3/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/03/eq/3/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/3/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/3/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/4",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/03/eq/4/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/03/eq/4/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/4/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/4/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/5",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/03/eq/5/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/03/eq/5/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/5/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/5/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/6",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/03/eq/6/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/03/eq/6/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/6/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/eq/6/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/03/mix",							{CHME}, F_FND, {0}, NULL},
		{"/mtx/03/mix/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/03/mix/fader",				{F32}, F_XET, {0}, NULL},
		{"/mtx/03/grp",							{CHGRP}, F_FND, {0}, NULL},
		{"/mtx/03/grp/dca",					{P32}, F_XET, {0}, NULL},
		{"/mtx/03/grp/mute",				{P32}, F_XET, {0}, NULL},
};
int Xmtx03_max = sizeof(Xmtx03) / sizeof(X32command);


X32command Xmtx04[] = {
		{"/mtx",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/04",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/04/config",						{BSCO}, F_FND, {0}, NULL},
		{"/mtx/04/config/name",				{S32}, F_XET, {0}, NULL},
		{"/mtx/04/config/icon",				{I32}, F_XET, {0}, NULL},
		{"/mtx/04/config/color",			{E32}, F_XET, {0}, Xcolors},
		{"/mtx/04/preamp",						{MXPR}, F_FND, {0}, NULL},
		{"/mtx/04/preamp/invert",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/dyn",							{MXDY}, F_FND, {0}, NULL},
		{"/mtx/04/dyn/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/dyn/mode",				{E32}, F_XET, {0}, Xdymode},
		{"/mtx/04/dyn/det",					{E32}, F_XET, {0}, Xdydet},
		{"/mtx/04/dyn/env",					{E32}, F_XET, {0}, Xdyenv},
		{"/mtx/04/dyn/thr",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/ratio",				{E32}, F_XET, {0}, Xdyrat},
		{"/mtx/04/dyn/knee",				{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/mgain",				{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/attack",				{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/hold",				{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/release",				{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/pos",					{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/04/dyn/mix",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/dyn/auto",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/dyn/filter",					{CHDF}, F_FND, {0}, NULL},
		{"/mtx/04/dyn/filter/on",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/dyn/filter/type",			{E32}, F_XET, {0}, Xdyftyp},
		{"/mtx/04/dyn/filter/f",			{F32}, F_XET, {0}, NULL},
		{"/mtx/04/insert",						{CHIN}, F_FND, {0}, NULL},
		{"/mtx/04/insert/on",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/insert/pos",				{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/04/insert/sel",				{E32}, F_XET, {0}, Xisel},
		{"/mtx/04/eq",							{OFFON}, F_FND, {1}, NULL},
		{"/mtx/04/eq/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/eq/1",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/04/eq/1/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/04/eq/1/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/1/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/1/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/2",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/04/eq/2/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/04/eq/2/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/2/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/2/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/3",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/04/eq/3/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/04/eq/3/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/3/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/3/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/4",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/04/eq/4/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/04/eq/4/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/4/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/4/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/5",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/04/eq/5/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/04/eq/5/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/5/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/5/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/6",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/04/eq/6/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/04/eq/6/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/6/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/eq/6/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/04/mix",							{CHME}, F_FND, {0}, NULL},
		{"/mtx/04/mix/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/04/mix/fader",				{F32}, F_XET, {0}, NULL},
		{"/mtx/04/grp",							{CHGRP}, F_FND, {0}, NULL},
		{"/mtx/04/grp/dca",					{P32}, F_XET, {0}, NULL},
		{"/mtx/04/grp/mute",				{P32}, F_XET, {0}, NULL},
};
int Xmtx04_max = sizeof(Xmtx04) / sizeof(X32command);


X32command Xmtx05[] = {
		{"/mtx",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/05",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/05/config",						{BSCO}, F_FND, {0}, NULL},
		{"/mtx/05/config/name",				{S32}, F_XET, {0}, NULL},
		{"/mtx/05/config/icon",				{I32}, F_XET, {0}, NULL},
		{"/mtx/05/config/color",			{E32}, F_XET, {0}, Xcolors},
		{"/mtx/05/preamp",						{MXPR}, F_FND, {0}, NULL},
		{"/mtx/05/preamp/invert",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/dyn",							{MXDY}, F_FND, {0}, NULL},
		{"/mtx/05/dyn/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/dyn/mode",				{E32}, F_XET, {0}, Xdymode},
		{"/mtx/05/dyn/det",					{E32}, F_XET, {0}, Xdydet},
		{"/mtx/05/dyn/env",					{E32}, F_XET, {0}, Xdyenv},
		{"/mtx/05/dyn/thr",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/ratio",				{E32}, F_XET, {0}, Xdyrat},
		{"/mtx/05/dyn/knee",				{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/mgain",				{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/attack",				{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/hold",				{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/release",				{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/pos",					{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/05/dyn/mix",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/dyn/auto",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/dyn/filter",					{CHDF}, F_FND, {0}, NULL},
		{"/mtx/05/dyn/filter/on",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/dyn/filter/type",			{E32}, F_XET, {0}, Xdyftyp},
		{"/mtx/05/dyn/filter/f",			{F32}, F_XET, {0}, NULL},
		{"/mtx/05/insert",						{CHIN}, F_FND, {0}, NULL},
		{"/mtx/05/insert/on",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/insert/pos",				{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/05/insert/sel",				{E32}, F_XET, {0}, Xisel},
		{"/mtx/05/eq",							{OFFON}, F_FND, {1}, NULL},
		{"/mtx/05/eq/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/eq/1",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/05/eq/1/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/05/eq/1/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/1/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/1/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/2",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/05/eq/2/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/05/eq/2/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/2/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/2/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/3",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/05/eq/3/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/05/eq/3/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/3/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/3/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/4",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/05/eq/4/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/05/eq/4/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/4/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/4/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/5",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/05/eq/5/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/05/eq/5/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/5/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/5/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/6",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/05/eq/6/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/05/eq/6/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/6/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/eq/6/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/05/mix",							{CHME}, F_FND, {0}, NULL},
		{"/mtx/05/mix/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/05/mix/fader",				{F32}, F_XET, {0}, NULL},
		{"/mtx/05/grp",							{CHGRP}, F_FND, {0}, NULL},
		{"/mtx/05/grp/dca",					{P32}, F_XET, {0}, NULL},
		{"/mtx/05/grp/mute",				{P32}, F_XET, {0}, NULL},
};
int Xmtx05_max = sizeof(Xmtx05) / sizeof(X32command);


X32command Xmtx06[] = {
		{"/mtx",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/06",								{BSCO}, F_FND, {0}, NULL},
		{"/mtx/06/config",						{BSCO}, F_FND, {0}, NULL},
		{"/mtx/06/config/name",				{S32}, F_XET, {0}, NULL},
		{"/mtx/06/config/icon",				{I32}, F_XET, {0}, NULL},
		{"/mtx/06/config/color",			{E32}, F_XET, {0}, Xcolors},
		{"/mtx/06/preamp",						{MXPR}, F_FND, {0}, NULL},
		{"/mtx/06/preamp/invert",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/dyn",							{MXDY}, F_FND, {0}, NULL},
		{"/mtx/06/dyn/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/dyn/mode",				{E32}, F_XET, {0}, Xdymode},
		{"/mtx/06/dyn/det",					{E32}, F_XET, {0}, Xdydet},
		{"/mtx/06/dyn/env",					{E32}, F_XET, {0}, Xdyenv},
		{"/mtx/06/dyn/thr",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/ratio",				{E32}, F_XET, {0}, Xdyrat},
		{"/mtx/06/dyn/knee",				{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/mgain",				{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/attack",				{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/hold",				{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/release",				{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/pos",					{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/06/dyn/mix",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/dyn/auto",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/dyn/filter",					{CHDF}, F_FND, {0}, NULL},
		{"/mtx/06/dyn/filter/on",			{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/dyn/filter/type",			{E32}, F_XET, {0}, Xdyftyp},
		{"/mtx/06/dyn/filter/f",			{F32}, F_XET, {0}, NULL},
		{"/mtx/06/insert",						{CHIN}, F_FND, {0}, NULL},
		{"/mtx/06/insert/on",				{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/insert/pos",				{E32}, F_XET, {0}, Xdyppos},
		{"/mtx/06/insert/sel",				{E32}, F_XET, {0}, Xisel},
		{"/mtx/06/eq",							{OFFON}, F_FND, {1}, NULL},
		{"/mtx/06/eq/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/eq/1",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/06/eq/1/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/06/eq/1/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/1/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/1/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/2",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/06/eq/2/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/06/eq/2/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/2/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/2/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/3",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/06/eq/3/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/06/eq/3/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/3/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/3/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/4",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/06/eq/4/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/06/eq/4/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/4/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/4/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/5",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/06/eq/5/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/06/eq/5/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/5/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/5/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/6",						{CHEQ}, F_FND, {0}, NULL},
		{"/mtx/06/eq/6/type",				{E32}, F_XET, {0}, Xeqty2},
		{"/mtx/06/eq/6/f",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/6/g",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/eq/6/q",					{F32}, F_XET, {0}, NULL},
		{"/mtx/06/mix",							{CHME}, F_FND, {0}, NULL},
		{"/mtx/06/mix/on",					{E32}, F_XET, {0}, OffOn},
		{"/mtx/06/mix/fader",				{F32}, F_XET, {0}, NULL},
		{"/mtx/06/grp",							{CHGRP}, F_FND, {0}, NULL},
		{"/mtx/06/grp/dca",					{P32}, F_XET, {0}, NULL},
		{"/mtx/06/grp/mute",				{P32}, F_XET, {0}, NULL},
};
int Xmtx06_max = sizeof(Xmtx06) / sizeof(X32command);

X32command	*Xmtxset[6] = {
		Xmtx01, Xmtx02, Xmtx03,
		Xmtx04, Xmtx05, Xmtx06,
};

#endif /* X32MTX_H_ */