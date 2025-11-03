#define GP_BA 0x50004000


// Register Map
#define GP_PMD 		0x000
#define GP_OFFD 	0x004
#define GP_DOUT 	0x008
#define GP_DMASK 	0x00C
#define GP_PIN 		0x010
#define GP_DBEN 	0x014
#define GP_IMD 		0x018
#define GP_IEN 		0x01C
#define GP_ISRC 	0x020


// pin
#define E_GPA 0
#define E_GPB 1
#define E_GPC 2
#define E_GPD 3
#define E_GPE 4

// mode 
#define E_IO_INPUT 0
#define E_IO_OUTPUT 1
#define E_IO_Open_Drain 2
#define E_IO_Quasi_bidiretional 3

void DrvGPIO_Open (unsigned int port, unsigned int num, unsigned int mode);
void DrvGPIO_ClrBit (unsigned int port, unsigned int num);
void DrvGPIO_SetBit (unsigned int port, unsigned int num);

void DrvGPIO_Bounce(unsigned int port, unsigned int num);
unsigned int DrvGPIO_GetBit(unsigned int port);

void DrvSYS_Delay (unsigned int n);

unsigned int scan_KeyBOARD();
