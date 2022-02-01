/*
 * SPI_prv.h
 *
 * Created: 1/25/2022
 * Author : Abdelrhman Elsawy
 */


#ifndef SPI_PRV_H_
#define SPI_PRV_H_

/*===================================================
 * SPI Registers BITs
 *===================================================*/

/* Register – SPCR */
#define SPIE_BIT		7
#define SPE_BIT			6
#define DORD_BIT		5
#define MSTR_BIT		4
#define CPOL_BIT		3
#define CPHA_BIT		2
#define SPR1_BIT		1
#define SPR0_BIT		0

/* Register – SPSR */
#define SPIF_BIT		7
#define WCOL_BIT		6
// 5 -> 1 Reserved BITs 
#define SPI2X_BIT		0


/*=========================================================
 * Config macros
 *=========================================================*/

#define MASTER		0
#define SLAVE		1

#define PRESCALER_4				0
#define PRESCALER_16			1
#define PRESCALER_64			2
#define PRESCALER_128			3


#endif /* SPI_PRV_H_ */