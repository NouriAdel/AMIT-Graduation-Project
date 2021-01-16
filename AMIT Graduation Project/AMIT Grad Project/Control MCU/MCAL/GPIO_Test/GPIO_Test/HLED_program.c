/**************************************************************************/
/* Name:    HLED_program.c                                                */
/* Author:  Ahmed Ashraf                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains LED module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLED_private.h"
#include "HLED_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

/*This function is responsible for initializing a chosen LED as OUTPUT*/
void hled_init(u8_t led_number)
{
	/*Switching over LED numbers*/
	switch(led_number)
	{
		/*In LED0 case*/
		case LED0:
			/*Set LED0 pin to OUTPUT*/
			mdio_pinStatus(LED0_PORT,LED0_PIN,OUTPUT);
			break;
			
		/*In case of LED1*/
		case LED1:
			/*Set the corresponding LED pin to output*/
			mdio_pinStatus(LED1_PORT,LED1_PIN,OUTPUT);
			break;
			
		/*In case of LED2*/
		case LED2:
			/*Set the corresponding LED pin to output*/
			mdio_pinStatus(LED2_PORT,LED2_PIN,OUTPUT);
			break;
	}
	/*Return from this function*/
	return;
}

/*This function is responsible for setting the chosen LED to ON mode*/
void hled_ledON(u8_t led_number)
{
	/*Switching over LEDs*/
	switch(led_number)
	{
		/*In case of LED0*/
		case LED0:
		/*Set LED0 pin to HIGH level*/
		mdio_setPinValue(LED0_PORT,LED0_PIN,HIGH);
		break;
		
		/*In case of LED1*/
		case LED1:
		/*Set the corresponding port pin to high*/
		mdio_setPinValue(LED1_PORT,LED1_PIN,HIGH);
		break;
		
		/*In case of LED2*/
		case LED2:
		/*Set the corresponding port pin to high*/
		mdio_setPinValue(LED2_PORT,LED2_PIN,HIGH);
		break;
	}
	
	/*Return from this function*/
	return;
}

/*This function is responsible for setting the chosen LED to OFF mode*/
void hled_ledOFF(u8_t led_number)
{
	/*Switching over LEDs*/
	switch(led_number)
	{
		/*In case of LED0*/
		case LED0:
		/*Set the corresponding port pin to low*/
		mdio_setPinValue(LED0_PORT,LED0_PIN,LOW);
		break;
		
		/*In case of LED1*/
		case LED1:
		/*Set the corresponding port pin to low*/
		mdio_setPinValue(LED1_PORT,LED1_PIN,LOW);
		break;
		
		/*In case of LED2*/
		case LED2:
		/*Set the corresponding port pin to low*/
		mdio_setPinValue(LED2_PORT,LED2_PIN,LOW);
		break;
	}
	
	/*Return from this function*/
	return;
}