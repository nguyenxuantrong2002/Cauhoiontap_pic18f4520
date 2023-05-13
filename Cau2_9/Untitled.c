#include<p18f4520.h>
#include<ADC.h>

#pragma config OSC=HS, MCLRE=ON, WDT=OFF

#define LED11 PORTEbits.RE1

void main(void){
	int RADC0;
	float Vin;
	TRISA=0x02;
	TRISD=0x00;
	TRISC=0x00;
	ADCON1=0x0D;
	TRISE=0x00;
	/*OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_12_TAD,
			ADC_CH1 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS,
			13);*/
	while(1){
		OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_12_TAD,
			ADC_CH1 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS,
			13);
		ConvertADC();
		while(BusyADC());
		RADC0=ReadADC();
		CloseADC();
		Vin=(5.0*RADC0)/1023;
		PORTD=RADC0%256;
		PORTC=RADC0/256;
		if(Vin>=2) LED11=1;
		else LED11=0;
	}
}