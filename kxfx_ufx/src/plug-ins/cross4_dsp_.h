
#ifndef _NO_STATICS

const char* const cross4_name		= "Crossover-4";
const char* const cross4_copyright	= UCOPYRIGHT;
const char* const cross4_engine		= "";
const char* const cross4_created	= "Mar 16 2003";
const char* const cross4_comment	= "4th-Order Crossover, 24dB/octave; $nobypass";
const char* const cross4_guid		= "9211B061-7871-11D8-B0D1-8B8FB634CD13";

const int cross4_itramsize	= 0x00000; // 0.00 ms (0 samples)
const int cross4_xtramsize	= 0x00000; // 0 ms (0 samples)

#define R(i)
#define _	0xFFFF,
const dsp_register_info cross4_info[] =
{
R(0)	{"L", 		0x4000u, 0x07, _ 0x00000000},	// input
R(1)	{"R", 		0x4001u, 0x07, _ 0x00000000},	// input
R(2)	{"lo L", 			0x8000u, 0x08, _ 0x00000000},	// output
R(3)	{"hi L", 			0x8001u, 0x08, _ 0x00000000},	// output
R(4)	{"lo R", 			0x8002u, 0x08, _ 0x00000000},	// output
R(5)	{"hi R", 			0x8003u, 0x08, _ 0x00000000},	// output
R(6)	{"b", 			0x8004u, 0x01, _ 0x6F68090D},	// static, 0.87
R(7)	{"a2", 			0x8005u, 0x01, _ 0x77208A7F},	// static, 0.931
R(8)	{"a3", 			0x8006u, 0x01, _ 0x9097CC6B},	// static
R(9)	{"lz1", 		0x8007u, 0x01, _ 0x00000000},	// static
R(10)	{"lz2", 		0x8008u, 0x01, _ 0x00000000},	// static
R(11)	{"lz3", 		0x8009u, 0x01, _ 0x00000000},	// static
R(12)	{"lz4", 		0x800Au, 0x01, _ 0x00000000},	// static
R(13)	{"lz5", 		0x800Bu, 0x01, _ 0x00000000},	// static
R(14)	{"lz6", 		0x800Cu, 0x01, _ 0x00000000},	// static
R(15)	{"rz1", 		0x800Du, 0x01, _ 0x00000000},	// static
R(16)	{"rz2", 		0x800Eu, 0x01, _ 0x00000000},	// static
R(17)	{"rz3", 		0x800Fu, 0x01, _ 0x00000000},	// static
R(18)	{"rz4", 		0x8010u, 0x01, _ 0x00000000},	// static
R(19)	{"rz5", 		0x8011u, 0x01, _ 0x00000000},	// static
R(20)	{"rz6", 		0x8012u, 0x01, _ 0x00000000},	// static
R(21)	{"i", 			0x8013u, 0x03, _ 0x00000000},	// temp
R(22)	{"x", 			0x8014u, 0x03, _ 0x00000000},	// temp
R(23)	{"y", 			0x8015u, 0x03, _ 0x00000000},	// temp    
/*R(20)	{"DC1", 		0x8016u, 0x01, _ 0x00000000},	// static       
R(20)	{"DC2", 		0x8017u, 0x01, _ 0x00000000},	// static  */
};
#undef _
#undef R

#define I(i)
const dsp_code cross4_code[] =
{
I(0)	{0x0, 0x8013u, 0x4000u, 0x2040u, 0x2040u},	// {macs,	R_I, R_IN1, 0x2040u, 0x2040u	},
I(1)	{0x0, 0x8014u, 0x2040u, 0x8013u, 0x8004u},	// {macs,	R_X, 0x2040u, R_I, R_B	},
I(2)	{0x4, 0x8015u, 0x8014u, 0x8007u, 0x2051u},	// {macints,	R_Y, R_X, R_LZ1, 0x2051u	},
I(3)	{0x1, 0x2040u, 0x8014u, 0x8015u, 0x8005u},	// {macsn,	0x2040u, R_X, R_Y, R_A2	},
I(4)	{0x1, 0x8007u, 0x2056u, 0x8008u, 0x204Du},	// {macsn,	R_LZ1, 0x2056u, R_LZ2, 0x204Du	},
I(5)	{0x0, 0x8008u, 0x8014u, 0x8015u, 0x8006u},	// {macs,	R_LZ2, R_X, R_Y, R_A3	},
I(6)	{0x4, 0x8001u, 0x8015u, 0x8009u, 0x2051u},	// {macints,	R_H1, R_Y, R_LZ3, 0x2051u	},
I(7)	{0x1, 0x2040u, 0x8015u, 0x8001u, 0x8005u},	// {macsn,	0x2040u, R_Y, R_H1, R_A2	},
I(8)	{0x1, 0x8009u, 0x2056u, 0x800Au, 0x204Du},	// {macsn,	R_LZ3, 0x2056u, R_LZ4, 0x204Du	},
I(9)	{0x0, 0x800Au, 0x8015u, 0x8001u, 0x8006u},	// {macs,	R_LZ4, R_Y, R_H1, R_A3	},
I(10)	{0x1, 0x8014u, 0x800Bu, 0x8013u, 0x8006u},	// {macsn,	R_X, R_LZ5, R_I, R_A3	},
I(11)	{0x0, 0x8000u, 0x2056u, 0x8001u, 0x204Eu},	// {macs,	R_L1, 0x2056u, R_H1, 0x204Eu	},
I(12)	{0x0, 0x8015u, 0x8014u, 0x8013u, 0x204Eu},	// {macs,	R_Y, R_X, R_I, 0x204Eu	},
I(13)	{0x0, 0x2040u, 0x800Cu, 0x8015u, 0x8005u},	// {macs,	0x2040u, R_LZ6, R_Y, R_A2	},
I(14)	{0x0, 0x800Bu, 0x2056u, 0x8015u, 0x8005u},	// {macs,	R_LZ5, 0x2056u, R_Y, R_A2	},
I(15)	{0x0, 0x800Cu, 0x8013u, 0x8014u, 0x8006u},	// {macs,	R_LZ6, R_I, R_X, R_A3	},
I(16)	{0x0, 0x8013u, 0x4001u, 0x2040u, 0x2040u},	// {macs,	R_I, R_IN2, 0x2040u, 0x2040u	},
I(17)	{0x0, 0x8014u, 0x2040u, 0x8013u, 0x8004u},	// {macs,	R_X, 0x2040u, R_I, R_B	},
I(18)	{0x4, 0x8015u, 0x8014u, 0x800Du, 0x2051u},	// {macints,	R_Y, R_X, R_RZ1, 0x2051u	},
I(19)	{0x1, 0x2040u, 0x8014u, 0x8015u, 0x8005u},	// {macsn,	0x2040u, R_X, R_Y, R_A2	},
I(20)	{0x1, 0x800Du, 0x2056u, 0x800Eu, 0x204Du},	// {macsn,	R_RZ1, 0x2056u, R_RZ2, 0x204Du	},
I(21)	{0x0, 0x800Eu, 0x8014u, 0x8015u, 0x8006u},	// {macs,	R_RZ2, R_X, R_Y, R_A3	},
I(22)	{0x4, 0x8003u, 0x8015u, 0x800Fu, 0x2051u},	// {macints,	R_H2, R_Y, R_RZ3, 0x2051u	},
I(23)	{0x1, 0x2040u, 0x8015u, 0x8003u, 0x8005u},	// {macsn,	0x2040u, R_Y, R_H2, R_A2	},
I(24)	{0x1, 0x800Fu, 0x2056u, 0x8010u, 0x204Du},	// {macsn,	R_RZ3, 0x2056u, R_RZ4, 0x204Du	},
I(25)	{0x0, 0x8010u, 0x8015u, 0x8003u, 0x8006u},	// {macs,	R_RZ4, R_Y, R_H2, R_A3	},
I(26)	{0x1, 0x8014u, 0x8011u, 0x8013u, 0x8006u},	// {macsn,	R_X, R_RZ5, R_I, R_A3	},
I(27)	{0x0, 0x8002u, 0x2056u, 0x8003u, 0x204Eu},	// {macs,	R_L2, 0x2056u, R_H2, 0x204Eu	},
I(28)	{0x0, 0x8015u, 0x8014u, 0x8013u, 0x204Eu},	// {macs,	R_Y, R_X, R_I, 0x204Eu	},
I(29)	{0x0, 0x2040u, 0x8012u, 0x8015u, 0x8005u},	// {macs,	0x2040u, R_RZ6, R_Y, R_A2	},
I(30)	{0x0, 0x8011u, 0x2056u, 0x8015u, 0x8005u},	// {macs,	R_RZ5, 0x2056u, R_Y, R_A2	},
I(31)	{0x0, 0x8012u, 0x8013u, 0x8014u, 0x8006u},	// {macs,	R_RZ6, R_I, R_X, R_A3	},
};
#undef I

#endif

// register ids
#define R_IN1		0x4000u
#define R_IN2		0x4001u
#define R_L1		0x8000u
#define R_H1		0x8001u
#define R_L2		0x8002u
#define R_H2		0x8003u
#define R_B			0x8004u
#define R_A2		0x8005u
#define R_A3		0x8006u
#define R_LZ1		0x8007u
#define R_LZ2		0x8008u
#define R_LZ3		0x8009u
#define R_LZ4		0x800Au
#define R_LZ5		0x800Bu
#define R_LZ6		0x800Cu
#define R_RZ1		0x800Du
#define R_RZ2		0x800Eu
#define R_RZ3		0x800Fu
#define R_RZ4		0x8010u
#define R_RZ5		0x8011u
#define R_RZ6		0x8012u
#define R_I			0x8013u
#define R_X			0x8014u
#define R_Y			0x8015u            
/*#define R_DC1		0x8016u
#define R_DC2		0x8017u  */
