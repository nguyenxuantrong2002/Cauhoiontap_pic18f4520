#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB1
#define LED1 PORTCbits.RC4
#define LED2 PORTCbits.RC5
#define LED3 PORTCbits.RC6
#define LED4 PORTCbits.RC7

unsigned char count=0;

void low_isr(void);
#pragma code low_vector=0x08
void interrupt_at_low_vector(void){
	_asm GOTO low_isr _endasm
}
#pragma code
#pragma interrupt low_isr
void low_isr(void){
	unsigned char i;
	if(INTCONbits.INT0IF==1){
		count++;if(count==8) count=0;
		PORTC=count<<4;
		INTCONbits.INT0IF=0;
	}
}

void main(void){
	TRISC=0x00;
	TRISB=0x01;
	ADCON1=0x0F;
	
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	INTCONbits.INT0IE=1;

	while(1){
		LED4=1;Delay10KTCYx(50);
		LED4=0;Delay10KTCYx(50);
	}
}