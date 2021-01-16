/**************************************************************************/
/* Name:    HLED_interface.h                                              */
/* Author:  Ahmed Ashraf                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains interfacing information for LED module */
/**************************************************************************/

/*Header file guard*/
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

/************************************************************************/
/*                            Interfacing macros                        */
/************************************************************************/

/*System LEDs*/

#define LED1   1
#define LED2   2

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/*This function is responsible for initializing a chosen LED as OUTPUT*/
void hled_init(u8_t led_number);

/*This function is responsible for setting the chosen LED to ON mode*/
void hled_ledON(u8_t led_number);

/*This function is responsible for setting the chosen LED to OFF mode*/
void hled_ledOFF(u8_t led_number);

#endif /* HLED_INTERFACE_H_ */