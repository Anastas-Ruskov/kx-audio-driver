// kX Driver / kX Driver Interface / kX Driver Effects Library
// Copyright (c) Eugene Gavrilov and Max Mikhailov, 2001-2005.
// All rights reserved

/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

// 10kX microcode
// Patch name: 'Phat_EQ_Mono'

char *Phat_EQ_Mono_copyright="(c) Soeren Bovbjerg, 2002-2004";
char *Phat_EQ_Mono_engine="kX";
char *Phat_EQ_Mono_comment="Powerfull resonant filter! Warning :-)\nNo overload protection! Use input gain to compensate";
							  
char *Phat_EQ_Mono_created="2002/07/23";
char *Phat_EQ_Mono_guid="4f279d7b-d1b8-4937-84aa-516a2d72c625";

char *Phat_EQ_Mono_name="Phat EQ Mono";
int Phat_EQ_Mono_itramsize=0,Phat_EQ_Mono_xtramsize=0;

#define R_B0	0x8001
#define R_B1	0x8002
#define R_B2	0x8003
#define R_A1	0x8004
#define R_A2	0x8005
#define R_VOL	0x8006

dsp_register_info Phat_EQ_Mono_info[]={
	{ "in1",0x4000,0x7,0xffff,0x0 },
	{ "out",0x8000,0x8,0xffff,0x0 },
	{ "b0",0x8001,0x1,0xffff,0x7fffffff },
	{ "b1",0x8002,0x1,0xffff,0x0 },
	{ "b2",0x8003,0x1,0xffff,0x0 },
	{ "a1",0x8004,0x1,0xffff,0x0 },
	{ "a2",0x8005,0x1,0xffff,0x0 },
	{ "vol",0x8006,0x1,0xffff,0x7fffffff },
	{ "sca",0x8007,0x1,0xffff,0x2 },
	{ "lx1",0x8008,0x1,0xffff,0x0 },
	{ "lx2",0x8009,0x1,0xffff,0x0 },
	{ "ly1",0x800a,0x1,0xffff,0x0 },
	{ "ly2",0x800b,0x1,0xffff,0x0 },
	{ "rx1",0x800c,0x1,0xffff,0x0 },
	{ "rx2",0x800d,0x1,0xffff,0x0 },
	{ "ry1",0x800e,0x1,0xffff,0x0 },
	{ "ry2",0x800f,0x1,0xffff,0x0 },
	{ "t1",0x8010,0x3,0xffff,0x0 },
	{ "t2",0x8011,0x3,0xffff,0x0 },
	{ "in",0x8012,0x3,0xffff,0x0 },
};

dsp_code Phat_EQ_Mono_code[]={
	{ 0x0,0x8012,0x2040,0x4000,0x8006 },
	{ 0x0,0x2040,0x2040,0x2040,0x2040 },
	{ 0x7,0x8009,0x8008,0x8009,0x8003 },
	{ 0x7,0x8008,0x8012,0x8008,0x8002 },
	{ 0x7,0x8010,0x8010,0x8012,0x8001 },
	{ 0x7,0x800b,0x800a,0x800b,0x8005 },
	{ 0x7,0x8010,0x8010,0x800a,0x8004 },
	{ 0x0,0x8011,0x2056,0x2040,0x2040 },
	{ 0x4,0x800a,0x2040,0x8011,0x8007 },
	{ 0x0,0x2040,0x2040,0x2040,0x2040 },
	{ 0x7,0x800d,0x800c,0x800d,0x8003 },
	{ 0x7,0x800c,0x800a,0x800c,0x8002 },
	{ 0x7,0x8010,0x8010,0x800a,0x8001 },
	{ 0x7,0x800f,0x800e,0x800f,0x8005 },
	{ 0x7,0x8010,0x8010,0x800e,0x8004 },
	{ 0x0,0x8011,0x2056,0x2040,0x2040 },
	{ 0x4,0x800e,0x2040,0x8011,0x8007 },
	{ 0x0,0x8000,0x800e,0x2040,0x2040 },
};

