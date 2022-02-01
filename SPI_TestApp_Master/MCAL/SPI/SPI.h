/*
 * SPI.h
 *
 * Created: 1/25/2022
 * Author : Abdelrhman Elsawy
 */


#ifndef SPI_H_
#define SPI_H_


#include "SPI_prv.h"
#include "SPI_config.h"
#include "SPI_ERR_HANDLE.h"
#include "../../LIB/atmega32.h"
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Typedef.h"
#include "../DIO/DIO.h"

uint8_t SPI_u8Init(uint8_t SPI_MODE);
void SPI_SendByte(uint8_t S_Byte);
void SPI_SetData(uint8_t data);
uint8_t SPI_u8RecieveByte(uint8_t * R_Byte);
uint8_t SPI_u8SendString(uint8_t * S_str);
uint8_t SPI_u8ReceiveString(uint8_t * R_str);


#endif /* SPI_H_ */