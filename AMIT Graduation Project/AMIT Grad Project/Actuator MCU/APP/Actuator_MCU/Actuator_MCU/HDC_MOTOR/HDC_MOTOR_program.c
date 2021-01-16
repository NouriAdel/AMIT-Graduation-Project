/**************************************************************************/
/* Name:    MDC_MOTOR_program.h                                           */
/* Author:  Nouran Adel                                                   */
/* Version: v1.0                                                          */
/* Description: This file contains DC_MOTOR module logical program        */
/* Date: 15 January 2020                                                  */
/**************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

/************************************************************************/
/*                        Functions' definitions                        */
/************************************************************************/

void hdc_motor1_init()
{
	/*Set the 2 terminals and the enable as OUTPUT*/
	mdio_pinStatus(PORTD, PIN0, OUTPUT);
	mdio_pinStatus(PORTD, PIN1, OUTPUT);
	mdio_pinStatus(PORTD, PIN2, OUTPUT);
	
	/*Enable Motor 1*/
	mdio_setPinValue(PORTD, PIN2, HIGH);
	
	/*Return from this function*/
	return;
}

void hdc_motor2_init()
{
	/*Set the 2 terminals and the enable as OUTPUT*/
	mdio_pinStatus(PORTD, PIN3, OUTPUT);
	mdio_pinStatus(PORTD, PIN4, OUTPUT);
	mdio_pinStatus(PORTD, PIN5, OUTPUT);
	
	/*Enable Motor 1*/
	mdio_setPinValue(PORTD, PIN5, HIGH);
	
	/*Return from this function*/
	return;
}

void hdc_motor1_operate_dir1()
{
	/*Operate two terminals of Motor 1*/
	mdio_setPinValue(PORTD, PIN0, HIGH);
	mdio_setPinValue(PORTD, PIN1, LOW);
	
	/*Return from this function*/
	return;
}

void hdc_motor2_operate_dir1()
{
	/*Operate two terminals of Motor 2*/
	mdio_setPinValue(PORTD, PIN3, HIGH);
	mdio_setPinValue(PORTD, PIN4, LOW);
	
	/*Return from this function*/
	return;
}


void hdc_motor1_operate_dir2()
{
	/*Operate two terminals of Motor 1*/
	mdio_setPinValue(PORTD, PIN0, LOW);
	mdio_setPinValue(PORTD, PIN1, HIGH);
	
	/*Return from this function*/
	return;
}

void hdc_motor2_operate_dir2()
{
	/*Operate two terminals of Motor 2*/
	mdio_setPinValue(PORTD, PIN3, LOW);
	mdio_setPinValue(PORTD, PIN4, HIGH);
	
	/*Return from this function*/
	return;
}

void hdc_motor1_reverse()
{
	/*Operate two terminals of Motor 1*/
	mdio_togglePinValue(PORTD, PIN0);
	mdio_togglePinValue(PORTD, PIN1);
	
	/*Return from this function*/
	return;
}

void hdc_motor2_reverse()
{
	/*Operate two terminals of Motor 2*/
	mdio_togglePinValue(PORTD, PIN3);
	mdio_togglePinValue(PORTD, PIN4);
	
	/*Return from this function*/
	return;
}

void hdc_motor1_stop()
{
	/*Disable Motor 1*/
	mdio_setPinValue(PORTD, PIN2, LOW);
	
	/*Return from this function*/
	return;
}

void hdc_motor2_stop()
{
	/*Disbale Motor 2*/
	mdio_setPinValue(PORTD, PIN5, LOW);
	
	/*Return from this function*/
	return;
}