#include "mygpio.h"

void DrvGPIO_Open (unsigned int port, unsigned int num, unsigned int mode)
{
	unsigned int  *PMD;
	PMD	= (unsigned int *)(GP_BA + (port * 0x40) + GP_PMD);
	*PMD &= ~(0x3 << (num*2));
	*PMD |= (mode << (num*2));
}

void DrvGPIO_ClrBit (unsigned int port, unsigned int num)
{
	unsigned int  *DOUT;
	DOUT = (unsigned int *)(GP_BA + (port * 0x40) + GP_DOUT);
	*DOUT &= ~(1 << num);
}

void DrvGPIO_SetBit (unsigned int port, unsigned int num)
{
	unsigned int  *DOUT;
	DOUT = (unsigned int *)(GP_BA + (port * 0x40) + GP_DOUT);
	*DOUT |= (1 << num);
}

//2025/10/30
void DrvGPIO_Bounce(unsigned int port, unsigned int num)
{
	unsigned int *BOUNCE; 
	BOUNCE = (unsigned int *)(GP_BA + (port * 0x40) + GP_DBEN);
	*BOUNCE |= (1 << num);
}

unsigned int DrvGPIO_GetBit(unsigned int port)
{
	unsigned int *PIN;
  PIN = (unsigned int *)(GP_BA + (port * 0x40) + GP_PIN);
  return *PIN;
}

//keyboard_scan
unsigned int scan_KeyBOARD(){
	unsigned int input;
	unsigned int key;
	for (int col = 0; col < 3; col++){
		DrvGPIO_SetBit(E_GPA, 0);
		DrvGPIO_SetBit(E_GPA, 1);
		DrvGPIO_SetBit(E_GPA, 2);
		DrvGPIO_ClrBit(E_GPA, col);
		
		DrvSYS_Delay(10000);
		
		input = DrvGPIO_GetBit(E_GPA) >> 3 &0x07;
		if (input != 0x07){
			for (int row = 0; row < 3; row++){
				if (!(input & (1 << row))){
					key = row *3 + col + 1;
					return key;
				}
		}
	}
 }
	return 0;
}


void DrvSYS_Delay (unsigned int n)
{
	for ( int t = 0; t < n; t++); 
}
