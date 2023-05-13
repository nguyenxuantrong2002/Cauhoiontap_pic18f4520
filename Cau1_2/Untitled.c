#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0

unsigned char count=0, x=0b1;

void main(void){
	TRISB=0x01;
	TRISD=0x00;
	ADCON1=0x0F;

	while(count<5){
		if(PB1==0){
			while(PB1==0);
			PORTD=x;
			x=x<<1;
			count++;
		}
	}PORTD=0x0F;
	while(1);
}