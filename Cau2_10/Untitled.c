#include<p18f4520.h>
#include<adc.h>

#pragma config OSC=HS, MCLRE=ON, WDT=OFF

#define LED11 PORTEbits.RE1

void main(void){
	int RADC4;
	float Vin;
	TRISA=0x20;
	TRISD=0x00;
	TRISC=0x00;
	TRISE=0x00;
	ADCON1=0x0A;
	while(1){
		OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_12_TAD,
				ADC_CH4 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS,
				10);
		ConvertADC();
		while(BusyADC());
		RADC4=ReadADC();
		CloseADC();
		PORTD=RADC4%256;
		PORTC=RADC4/256;
		Vin=(5.0*RADC4)/1023;
		if(Vin>=2&&Vin<=3) LED11=1;
		else LED11=0;
	}
}