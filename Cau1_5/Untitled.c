#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB1

unsigned char count=0;

void main(void){
	TRISD=0x00;
	TRISB=0x03;
	ADCON1=0x0F;
	while(1){
		if(PB1==0){
			if(PB2==0){
				while(PB2==0);
				count++;
			}
			if(count==1) PORTD=0b1000;
			else if(count==2) PORTD=0b100;
			else if (count>=3) PORTD=0b1100;
		}else{
			PORTD=0;
			count=0;
		}
	}
}