#include<p18f4520.h>
#include<timers.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define Pulse PORTCbits.RC2


unsigned char count=0;


void main(void){
	TRISC=0x00;
	ADCON1=0x0F;
	T0CONbits.T08BIT=1;
	T0CONbits.T0CS=0;
	T0CONbits.PSA=0;
	T0CONbits.T0PS2=0;
	T0CONbits.T0PS1=0;
	T0CONbits.T0PS0=1;

	while(1){
		TMR0L=256-150;
		T0CONbits.TMR0ON=1;
		while(INTCONbits.TMR0IF==0);
		T0CONbits.TMR0ON=0;
		INTCONbits.TMR0IF=0;
		Pulse=~Pulse;
	}
}