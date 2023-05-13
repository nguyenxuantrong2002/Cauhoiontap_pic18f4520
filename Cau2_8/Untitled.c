#include<p18f4520.h>
#include<pwm.h>

#pragma config OSC=HS, MCLRE=ON, WDT=OFF

#define PB1 PORTBbits.RB0

unsigned char count=0;

void main(void){
	TRISB=0x01;
	ADCON1=0x0F;
	
	T2CONbits.T2CKPS1=0;
	T2CONbits.T2CKPS0=1;
	OpenPWM2(25);
	SetDCPWM2(90);
	while(count<3){
		if(PB1==0){
			while(PB1==0);
			count++;
		}if(count==1) SetDCPWM2(30);
		else if(count==2) SetDCPWM2(70);
	}SetDCPWM2(90);
	while(1);
}