/**************************************************************************/
/* Name:    MUART_interface.h                                             */
/* Author:  Nouran Adel                                                   */
/* Version: v1.0                                                          */
/* Description: This file contains UART module logical program            */
/* Date: 18 December 2020                                                 */
/**************************************************************************/


/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MUART_private.h"
#include "MUART_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

/************************************************************************/
/*                              Global Variables                        */
/************************************************************************/

u8_t timeout_var = 0;
/************************************************************************/
/*                        Functions' definitions                         */
/************************************************************************/

/*This function is responsible for*/
void muart_init(u16_t baudrate)
{
	/*Enable Rx and Tx*/
	SET_BIT(MUART_UCSRB, 4);
	SET_BIT(MUART_UCSRB, 3);
	
	/*Choosing Asynchronous mode, Disbale parity, Data length is 8-bits*/
	MUART_UCSRC = (0x80) | (0x06) ;
	
	/*Setting low baud rate register*/
	MUART_UBRRL = (u8_t)baudrate;
	
	/*Setting high baud rate register*/
	MUART_UBRRH = (u8_t)(baudrate >> 8);
	
	/*Return from this function*/
	return;
}

/*This function is responsible for*/
void muart_sendByte(u8_t data)
{
	/*Reset timeout variable*/
	timeout_var = 0;
	
	/*Checking if UDR register is empty or not*/
	if(GET_BIT(MUART_UDR, 5))
	{
		/*Transmitting data over Tx pin*/
		MUART_UDR = data;
		
		/*Make sure that the data has been transmitted or timeout happens*/
		while(GET_BIT(MUART_UCSRA, 6) == 0 && timeout_var < 10)
		{
			/*Increase timeout variable*/
			timeout_var++;
			
			/*Dealy for 1ms*/
			_delay_ms(1);
		}
		
		/*Clearing Tx flag*/
		SET_BIT(MUART_UCSRA, 6);
	}
	else
	{
		/*Report error*/
	}
	
	/*Return from this function*/
	return;
}

/*This function is responsible for*/
void muart_recvByte(u8_t* data)
{
	/*Checking that there is a new data or not*/
	if(GET_BIT(MUART_UCSRA, 7))
	{
		/*Reading the new data*/
		*data = MUART_UDR;
	}
	else
	{
		/*Report error*/
	}
	
	/*Return from this function*/
	return;
}

/*This function is responsible for sending stream of data over UART data bus*/
void muart_sendStream(u8_t* data_stream, u8_t data_size)
{
	/*Sending stream of data according to their size*/
	while(data_size--)
	{
		/*Send one byte at a time*/
		muart_sendByte(*data_stream);
		
		/*Increase data pointer*/
		data_stream++;
	}
	
	/*Return from this function*/
	return;
}
