/*
 * SPI_TestApp.c
 *
 * Created: 1/25/2022
 * Author : Abdelrhman Elsawy
 */ 

#include "../MCAL/SPI/SPI.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/UART/UART.h"

int main(void)
{
	SPI_u8Init(SLAVE);
	UART_u8Init();
	TIMER0_u8Init();
	DIO_u8SetPortDirection(PORTC,OUTPUTPORT);
	uint8_t R_char  = 'A' ;		
    while (1) 
    {	
		SPI_u8RecieveByte(&R_char);
		UART_u8SendByte(R_char);
    }
}

