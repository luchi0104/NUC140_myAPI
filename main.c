//lab04 RGBLED + LED

#include "mygpio.h"

void SystemInit (void)
{
	
} 

void Init_KEYBOARD(){
	DrvGPIO_Open(E_GPA, 0, E_IO_Quasi_bidiretional);
	DrvGPIO_Open(E_GPA, 1, E_IO_Quasi_bidiretional);
	DrvGPIO_Open(E_GPA, 2, E_IO_Quasi_bidiretional);
	DrvGPIO_Open(E_GPA, 3, E_IO_Quasi_bidiretional);
	DrvGPIO_Open(E_GPA, 4, E_IO_Quasi_bidiretional);
	DrvGPIO_Open(E_GPA, 5, E_IO_Quasi_bidiretional);
	
	DrvGPIO_Bounce(E_GPA, 0);
	DrvGPIO_Bounce(E_GPA, 1);
	DrvGPIO_Bounce(E_GPA, 2);
	DrvGPIO_Bounce(E_GPA, 3);
	DrvGPIO_Bounce(E_GPA, 4);
	DrvGPIO_Bounce(E_GPA, 5);
}

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

void Init_LED()
{	
	// initialize GPIO pins RGB LED
	DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT); // GPA12 pin set to output mode
	DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT); // GPA13 pin set to output mode
	DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT); // GPA14 pin set to output mode

	// initialize GPIO pins LED
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); // GPA12 pin set to output mode
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT); // GPA13 pin set to output mode
	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT); // GPA14 pin set to output mode
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT); // GPA14 pin set to output mode
}    

void RGB_LED()
{
    // turn on pin 12 LED
    DrvGPIO_ClrBit(E_GPA,12);		
    DrvGPIO_SetBit(E_GPA,13);		
    DrvGPIO_SetBit(E_GPA,14);		
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 

    // turn on pin 13 LED
    DrvGPIO_SetBit(E_GPA,12);		
    DrvGPIO_ClrBit(E_GPA,13);		
    DrvGPIO_SetBit(E_GPA,14);		
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 

    // turn on pin 14 LED
    DrvGPIO_SetBit(E_GPA,12);		
    DrvGPIO_SetBit(E_GPA,13);		
    DrvGPIO_ClrBit(E_GPA,14);		
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 

    // turn on all pin LED
    DrvGPIO_ClrBit(E_GPA,12);		
    DrvGPIO_ClrBit(E_GPA,13);	
    DrvGPIO_ClrBit(E_GPA,14);		
    DrvSYS_Delay(200000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 
}

void LED()
{
    // turn on pin 12 LED
    DrvGPIO_ClrBit(E_GPC,12);		
    DrvGPIO_SetBit(E_GPC,13);		
    DrvGPIO_SetBit(E_GPC,14);		
    DrvGPIO_SetBit(E_GPC,15);	
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);	

    // turn on pin 13 LED
    DrvGPIO_SetBit(E_GPC,12);		
    DrvGPIO_ClrBit(E_GPC,13);		
    DrvGPIO_SetBit(E_GPC,14);		
    DrvGPIO_SetBit(E_GPC,15);	
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);	

    // turn on pin 14 LED
    DrvGPIO_SetBit(E_GPC,12);		
    DrvGPIO_SetBit(E_GPC,13);		
    DrvGPIO_ClrBit(E_GPC,14);		
    DrvGPIO_SetBit(E_GPC,15);	
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);	

    // turn on pin 15 LED
    DrvGPIO_SetBit(E_GPC,12);		
    DrvGPIO_SetBit(E_GPC,13);	
    DrvGPIO_SetBit(E_GPC,14);		
    DrvGPIO_ClrBit(E_GPC,15);
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);
	
    // turn on all pin LED
    DrvGPIO_ClrBit(E_GPC,12);		
    DrvGPIO_ClrBit(E_GPC,13);	
    DrvGPIO_ClrBit(E_GPC,14);		
    DrvGPIO_ClrBit(E_GPC,15);
    DrvSYS_Delay(200000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);
} 


int main (void)
{	
	unsigned int prev_key = 0;
  unsigned int led_state[9] = {1,1,1,1,1,1,1,1,1}; // 1 = off, 0 = on
  Init_KEYBOARD();
  Init_LED();
    while(1){
        unsigned int key = scan_KeyBOARD();
				if (!led_state[7]){RGB_LED();}  
				if (!led_state[8]){LED();}
        if (key != 0 && key != prev_key) { 
            switch(key){
                case 1: led_state[0] ^= 1; DrvGPIO_SetBit(E_GPC,14); if(!led_state[0]) DrvGPIO_ClrBit(E_GPC,14); break;
                case 2: led_state[1] ^= 1; DrvGPIO_SetBit(E_GPC,13); if(!led_state[1]) DrvGPIO_ClrBit(E_GPC,13); break;
                case 3: led_state[2] ^= 1; DrvGPIO_SetBit(E_GPC,12); if(!led_state[2]) DrvGPIO_ClrBit(E_GPC,12); break;
                case 4: led_state[3] ^= 1; DrvGPIO_SetBit(E_GPA,13); if(!led_state[3]) DrvGPIO_ClrBit(E_GPA,13); break;
                case 5: led_state[4] ^= 1; DrvGPIO_SetBit(E_GPA,12); if(!led_state[4]) DrvGPIO_ClrBit(E_GPA,12); break;
                case 6: led_state[5] ^= 1; DrvGPIO_SetBit(E_GPC,15); if(!led_state[5]) DrvGPIO_ClrBit(E_GPC,15); break;
                case 7: led_state[7] ^= 1; break;
                case 8: led_state[8] ^= 1; break;
                case 9: led_state[6] ^= 1; DrvGPIO_SetBit(E_GPA,14); if(!led_state[6]) DrvGPIO_ClrBit(E_GPA,14); break;						
            }
        }
        prev_key = key;
    }
}
