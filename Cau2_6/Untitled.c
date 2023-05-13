#include<p18f4520.h>
#include<delays.h>
#include<timers.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define nchuc PORTCbits.RC6
#define ndvi PORTCbits.RC7
#define DATA PORTD
#define PB1 PORTCbits.RC0

char M[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};//Anode chung
unsigned char Code7seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int x;

void hienthi(unsigned char num){
	nchuc=1;
	DATA=M[num/10];Delay10KTCYx(10);
	nchuc=0;ndvi=1;
	DATA=M[num%10];Delay10KTCYx(10);
	ndvi=0;
}
void main(void){
	TRISD=0x00;
	TRISC=0x01;
	ADCON1=0x0F;
	T1CONbits.RD16=1;
	//T1CONbits.T1CKPS1=0;
	//T1CONbits.T1CKPS0=1;
	T1CONbits.TMR1CS=1;
	TMR1H=0;
	TMR1L=0;
	T1CONbits.TMR1ON=1;
	while(1){
		x=(TMR1H*256)+TMR1L;
		hienthi(x);
	}
}