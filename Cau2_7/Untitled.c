#include<p18f4520.h>
#include<pwm.h>

#pragma config OSC=HS, MCLRE=ON, WDT=OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB3

unsigned char bandau=30;

/*
void ngat_ngoai(void);
#pragma code high_vector=0x08
void ngat_cao(){
	ngat_ngoai();
}
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void){
	if(INTCONbits.INT0IF==1){
		bandau=45;
		INTCONbits.INT0IF=0;
	}if(INTCON3bits.INT2IF==1){
		bandau=60;
		INTCON3bits.INT2IF=0;
	}
}*/

void main(void){
	TRISB=0b1001;
	ADCON1=0x0F;

	T2CONbits.T2CKPS1=1;//he so chia tan 16

	OpenPWM2(36);
	//SetDCPWM2(30);
	while(1){
		if(PB1==0){
			SetDCPWM2(45);
		}else if(PB2==0){
			SetDCPWM2(60);
		}else SetDCPWM2(30);
	}
	
}