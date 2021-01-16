/**************************************************************************/
/* Name:    MSPI_program.c                                                */
/* Author:  Ahmed Ashraf                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains SPI module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

#define  F_CPU   16000000UL
#include "util/delay.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void mspi_init(u8_t data_mode, u8_t clk_prescaler)
{
	/*Enable master mode, Sending MSB first and Setting data mode*/
	MSPI_SPCR = (0x10) | (data_mode << 2);
	
	/*Check if the prescaler value is divisable by two or not*/
	if( (clk_prescaler % 2) == 0)
	{
		/*Enable SPI double speed*/
		SET_BIT(MSPI_SPSR, 0);				
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Set SPI clock*/
	MSPI_SPCR |= (clk_prescaler / 2);
	 
	/*Return from this function*/
	return;
}

void mspi_init_slave(u8_t data_mode, u8_t clk_prescaler)
{
	//MSPI_SPCR = (1 << SPE);
	//SET_BIT(MSPI_SPCR, 6);
	
	/*Enable master mode, Sending MSB first and Setting data mode*/
	MSPI_SPCR = (0x10) | (data_mode << 2);
	
	CLEAR_BIT(MSPI_SPCR, 4);
	
	/*Check if the prescaler value is divisable by two or not*/
	if( (clk_prescaler % 2) == 0)
	{
		/*Enable SPI double speed*/
		SET_BIT(MSPI_SPSR, 0);
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Set SPI clock*/
	MSPI_SPCR |= (clk_prescaler / 2);
	
	/*Return from this function*/
	return;
}

u8_t mspi_sendRecvByte(u8_t data)
{
	/*Variable used in timing out operations*/
	u16_t timeout_var = 0;
	
	/*Enable SPI peripheral*/
	SET_BIT(MSPI_SPCR, 6);
	
	/*Send master data*/
	MSPI_SPDR = data;
	
	/*Wait until data is transmitted or timeout in 10ms*/
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeout_var < 10000)
	{
		/*Increase timeout variable*/
		timeout_var++;
		
		/*Delay for 1us*/
		_delay_us(1);
	}
	
	/*Disable SPI peripheral*/
	CLEAR_BIT(MSPI_SPCR, 6);
	
	/*Return SPI slave data*/
	return MSPI_SPDR;
}

void mspi_sendStream(u8_t* data, u8_t data_size)
{	
	/*A variable used in looping operations*/
	u8_t looping_var = 0;
	
	/*Sending data stream*/
	for(looping_var = 0 ; looping_var < data_size ; looping_var++)
	{
		mspi_sendRecvByte(data[looping_var]);
	}
	
	/*Return from this function*/
	return;	
}

u8_t mspi_RecvByte_slave(void)
{
	/*Variable used in timing out operations*/
	u16_t timeout_var = 0;
	
	/*Enable SPI peripheral*/
	SET_BIT(MSPI_SPCR, 6);
	
	//while(!(MSPI_SPSR & (1 << SPIF)));
	
	/*Wait until data is transmitted or timeout in 10ms*/
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeout_var < 10000)
	{
		/*Increase timeout variable*/
		timeout_var++;
		
		/*Delay for 1us*/
		_delay_us(1);
	}
	
	/*Disable SPI peripheral*/
	CLEAR_BIT(MSPI_SPCR, 6);
	
	/*Return from this function*/
	return MSPI_SPDR;
}