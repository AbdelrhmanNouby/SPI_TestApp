/*
 * SPI.c
 *
 * Created: 1/25/2022
 * Author : Abdelrhman Elsawy
 */

#include "SPI.h"
#include "../TIMER0/TIMER0.h"

/* 
 * Description : initialize SPI Communication 
 * Arguments   : void
 * return      : SPI_Init_Error or STD_TYPES_OK in uint8_t    
 */
uint8_t SPI_u8Init(uint8_t SPI_MODE)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	if ( SPI_MODE == MASTER )
	{
		SPCR_REG |= SPI_PRESCALER ;				// set prescaler 
		CLR_BIT(SPSR_REG,SPI2X_BIT);			// clear duple speed bit 
		SET_BIT(SPCR_REG,MSTR_BIT);				// Set MSTR to Master Mode
		CLR_BIT(SPCR_REG,DORD_BIT);				// Send MSB First		
		SET_BIT(SPCR_REG,SPE_BIT);				// start SPI module 
		// set direction of SPI pins 
		SET_BIT(DDRB_REG,SPI_SCK_PIN);
		SET_BIT(DDRB_REG,SPI_MOSI_PIN);
		SET_BIT(DDRB_REG,SPI_SS_PIN);
		CLR_BIT(DDRB_REG,SPI_MISO_PIN);
		SET_BIT(PORTB_REG,SPI_SS_PIN);
	}
	else if ( SPI_MODE == SLAVE )
	{
		SPCR_REG |= SPI_PRESCALER ;					// set prescaler 
		CLR_BIT(SPSR_REG,SPI2X_BIT);				// clear duple speed bit
		CLR_BIT(SPCR_REG,MSTR_BIT);					// clear MSTR to SLAVE Mode
		CLR_BIT(SPCR_REG,DORD_BIT);					// Send MSB First				
		SET_BIT(SPCR_REG,SPE_BIT);					// start SPI module 	
		// set direction of SPI pins 
		CLR_BIT(DDRB_REG,SPI_SCK_PIN);
		CLR_BIT(DDRB_REG,SPI_MOSI_PIN);
		CLR_BIT(DDRB_REG,SPI_SS_PIN);
		SET_BIT(DDRB_REG,SPI_MISO_PIN);	
	}
	else 
		u8ErrorState = SPI_Init_Error ;
	return u8ErrorState ;
}

void SPI_SendByte(uint8_t S_Byte)
{
	CLR_BIT(PORTB_REG,SPI_SS_PIN);
	SPDR_REG = S_Byte ;											// load data to SPDR REG
	while ( GET_BIT(SPSR_REG,SPIF_BIT) == 0);				// stay to transfer be done 
	SET_BIT(PORTB_REG,SPI_SS_PIN);
}
void SPI_SetData(uint8_t data)
{
	SPDR_REG = data;
}
uint8_t SPI_u8RecieveByte(uint8_t * R_Byte)
{
		uint8_t u8ErrorState = STD_TYPES_OK ;
		if( R_Byte == NULL)
		{
			u8ErrorState = SPI_RecieveByte_Error ;
		}
		else
		{
			while ( GET_BIT(SPSR_REG,SPIF_BIT) == 0);					// stay to transfer be done
			*R_Byte = SPDR_REG ;										// get data from SPDR REG
		}
		return u8ErrorState;
}

uint8_t SPI_u8SendString(uint8_t * S_str)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// send characters until find the NULL
	if ( S_str == NULL)
	{
		u8ErrorState = SPI_RecieveByte_Error ;
	}
	else 
	{
		while(*S_str != '\0')
		{
			// send character by character
			SPI_SendByte(*S_str) ;
			S_str++;
		}
	}
	return u8ErrorState ;
}

uint8_t SPI_u8ReceiveString(uint8_t * R_str)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// send characters until find the NULL
	while(*R_str != '\0' )
	{
		// send character by character
		SPI_u8RecieveByte(R_str);
		R_str++;
	}
	*R_str = '\0';
	return u8ErrorState ;
}

