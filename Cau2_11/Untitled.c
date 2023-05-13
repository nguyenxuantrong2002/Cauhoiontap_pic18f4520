#include<p18f4520.h>
#include<usart.h>

#pragma config OSC=HS, MCLRE=ON, WDT=OFF

void main(void){
	unsigned char x;
	TRISC = 0X80;//=0b10000000 //chan RX co chieu vao, chan TX co chieu ra
	TRISD=0x00;
	ADCON1=0x0f;
	OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT &
			USART_CONT_RX & USART_BRGH_HIGH, 38);
	PIR1bits.TXIF=1;	//cho phep truyen byte dau tien
	while(BusyUSART());
	WriteUSART(0x41);
	WriteUSART(0x61);
	while(1){
		PORTD=ReadUSART();
	}
}