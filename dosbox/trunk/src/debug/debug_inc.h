/*
 *  Copyright (C) 2002  The DOSBox Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* Local Debug Function */
#include <curses.h>
#include "mem.h"

#define PAIR_BLACK_BLUE 1
#define PAIR_BYELLOW_BLACK 2


void DBGUI_StartUp(void);

struct DBGBlock {
	WINDOW * win_main;					/* The Main Window */
	WINDOW * win_reg;					/* Register Window */
	WINDOW * win_data;					/* Data Output window */
	WINDOW * win_code;					/* Disassembly/Debug point Window */
	WINDOW * win_out;					/* Text Output Window */
	Bit32u active_win;					/* Current active window */
	Bit32u input_y;
};


struct DASMLine {
	Bit32u pc;
	char dasm[80];
	PhysPt ea;
	Bit16u easeg;
	Bit32u eaoff;
};

extern DBGBlock dbg;


/* Local Debug Stuff */
Bitu DasmI386(char* buffer, PhysPt pc, Bitu cur_ip, bool bit32);
