/**************************************************************************/
/* Name:    HBLUETOOTH_interface.h                                        */
/* Author:  Nouran Adel                                                   */
/* Version: v1.0                                                          */
/* Description: This file contains BLUETOOTH module logical progra        */
/* Date: 15 January 2020                                                  */
/**************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "HBLUETOOTH_interface.h"
#include "MUART_interface.h"
#include "MUART_private.h"

/************************************************************************/
/*                        Functions' definitions                         */
/************************************************************************/

/*This function is responsible for initializing Bluetooth connection*/
void hbluetooth_init()
{
	/*Initialize UART*/
	muart_init(MUART_9600_BPS);
	
	/*Return from this function*/
	return;
}

/*This function is responsible for sending data from Bluetooth*/
void hbluetooth_start(u8_t* recv_var)
{
	/*Send data via UART*/
	muart_recvByte(&recv_var);
	
	/*Return from this function*/
	return;
}