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
	SPI_u8Init(MASTER);
	UART_u8Init();
	TIMER0_u8Init();
	uint8_t S_char  = 0xFF ;
	while (1)
	{
		UART_u8ReceiveByte(&S_char);
		SPI_SendByte(S_char);
					
	}
}


