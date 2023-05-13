#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0

void main(void){
	TRISD=0x00;
	TRISB=0x01;
	ADCON1=0x0F;
	while(1){
		if(PB1==0) PORTD=0b0;
		else{
			PORTD=0b1;Delay10KTCYx(100);
			PORTD=0b10;Delay10KTCYx(100);
			PORTD=0b100;Delay10KTCYx(100);
			PORTD=0b1000;Delay10KTCYx(100);
		}
	}
}