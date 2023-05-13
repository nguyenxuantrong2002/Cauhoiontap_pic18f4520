#include<p18f4520.h>
#include<timers.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define Pulse PORTBbits.RB2

void main(void){
	TRISB=0x00;
	ADCON1=0x0F;
	T1CONbits.RD16=0;
	T1CONbits.TMR1CS=0;
	T1CONbits.T1CKPS1=1;
	T1CONbits.T1CKPS0=1;
	while(1){
		TMR1H=(65536-133)/256;
		TMR1L=(65536-133)%256;
		T1CONbits.TMR1ON=1;
		while(PIR1bits.TMR1IF==0);
		T1CONbits.TMR1ON=0;
		PIR1bits.TMR1IF=0;
		Pulse=~Pulse;
	}
}

