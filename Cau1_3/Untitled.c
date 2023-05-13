#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0

unsigned char count=0;

void main(void){
	TRISD=0x00;
	TRISB=0x01;
	ADCON1=0x0F;
	while(1){
		if(PB1==0){
			while(PB1==0);
			count++;if(count==256) count=0;
		}PORTD=count%16;
	}
}