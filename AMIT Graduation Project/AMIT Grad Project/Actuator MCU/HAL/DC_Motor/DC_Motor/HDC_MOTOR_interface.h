/*************************************************************************************/
/* Name:    MDC_MOTOR_interface.h                                                    */
/* Author:  Nouran Adel                                                              */
/* Version: v1.0                                                                     */
/* Description: This file contains interfacing information for DC_MOTOR module       */
/* Date: 15 January 2020                                                             */
/*************************************************************************************/

/*Header file guard*/
#ifndef HDC_MOTOR_INTERFACE_H_
#define HDC_MOTOR_INTERFACE_H_

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/*Initialize Motor 1*/
void hdc_motor1_init();

/*Initialize Motor 2*/
void hdc_motor2_init();

/*Operate Motor 1*/
void hdc_motor1_operate_dir1();

/*Operate Motor 2*/
void hdc_motor2_operate_dir1();

/*Operate Motor 1 in reverse direction*/
void hdc_motor1_operate_dir2();

/*Operate Motor 2 in reverse direction*/
void hdc_motor2_operate_dir2();

/*Reverse the direction of Motor 1*/
void hdc_motor1_reverse();

/*Reverse the direction of Motor 2*/
void hdc_motor2_reverse();

/*Stop Motor 1*/
void hdc_motor1_stop();

/*Stop Motor 2*/
void hdc_motor2_stop();


#endif /* HDC_MOTOR_INTERFACE_H_ */