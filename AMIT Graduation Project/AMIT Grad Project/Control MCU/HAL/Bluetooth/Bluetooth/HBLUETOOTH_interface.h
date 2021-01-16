/********************************************************************************/
/* Name:    MBLUETOOTH_interface.h                                              */
/* Author:  Nouran Adel                                                         */
/* Version: v1.0                                                                */
/* Description: This file contains interfacing information for BLUETOOTH module */
/* Date: 15 January 2020                                                        */
/********************************************************************************/


/*Header file guard*/
#ifndef HBLUETOOTH_INTERFACE_H_
#define HBLUETOOTH_INTERFACE_H_


/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/*This function is responsible for initializing Bluetooth connection*/
void hbluetooth_init();

/*This function is responsible for sending data from Bluetooth*/
void hbluetooth_start(u8_t* recv_var);



#endif /* HBLUETOOTH_INTERFACE_H_ */