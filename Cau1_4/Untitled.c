#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB1


void main(void){
	TRISD=0x00;
	TRISB=0x03;
	ADCON1=0x0F;
	while(1){
		if(PB1==0&&PB2==0) PORTD=0x01;
		else if(PB1==0&&PB2==1) PORTD=0b0010;
		else if(PB1==1&&PB2==0) PORTD=0b0100;
		else PORTD=0b1000;
	}
}