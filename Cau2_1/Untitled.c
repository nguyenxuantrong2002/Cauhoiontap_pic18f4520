#include<p18f4520.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB1
#define LED1 PORTCbits.RC2
#define LED2 PORTCbits.RC4


void low_isr(void);
#pragma code low_vector=0x18
void interrupt_at_low_vector(void){
	_asm GOTO low_isr _endasm
}
#pragma code
#pragma interrupt low_isr
void low_isr(void){
	unsigned char i;
	if(INTCON3bits.INT1IF==1){
		LED1=0;
		for(i=0;i<10;i++){
			LED2=1;Delay10KTCYx(100);LED2=0;Delay10KTCYx(100);
		}INTCON3bits.INT1IF=0;
	}
}

void main(void){
	TRISC=0x00;
	TRISB=0x02;
	ADCON1=0x0F;
	
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	INTCON3bits.INT1IE=1;

	while(1){
		LED1=1;Delay10KTCYx(100);
		LED1=0;Delay10KTCYx(100);
	}
}