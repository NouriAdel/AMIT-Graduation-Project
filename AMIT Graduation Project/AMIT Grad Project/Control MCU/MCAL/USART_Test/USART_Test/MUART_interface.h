/***************************************************************************/
/* Name:    MUART_interface.h                                              */
/* Author:  Nouran Adel                                                    */
/* Version: v1.0                                                           */
/* Description: This file contains interfacing information for UART module */
/* Date: 18 December 2020                                                  */
/***************************************************************************/


/*Header file guard*/
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define MUART_2400_BPS		(416)
#define MUART_4800_BPS		(207)
#define MUART_9600_BPS		(103)
#define MUART_19200_BPS		(51)
#define MUART_115200_BPS	(8)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/*This function is responsible for initializing UART module*/
void muart_init(u16_t baudrate);

/*This function is responsible for sending 1byte over UART data bus */
void muart_sendByte(u8_t data);

/*This function is responsible for receiving 1byte from UART data bus*/
void muart_recvByte(u8_t* data);

/*This function is responsible for sending stream of data over UART data bus*/
void muart_sendStream(u8_t* data_stream, u8_t data_size);

#endif /* MUSART_INTERFACE_H_ */