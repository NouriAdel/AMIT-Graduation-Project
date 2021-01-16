
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "HDC_MOTOR_interface.h"
#include "HLED_interface.h"


#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	/*Initialize Actuator MCU as slave*/
	mdio_pinStatus(PORTB, PIN4, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN5, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN6, OUTPUT);
	mdio_pinStatus(PORTB, PIN7, INPUT_FLOAT);
		
	/*Initialize SPI for Slave*/
	mspi_init_slave(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);
	
	/*Initialize Motor 1*/
	hdc_motor1_init();
	
	/*Initialize Motor 2*/
	hdc_motor2_init();
	
	/*Initialize LED 1*/
	hled_init(LED1);

    /* Replace with your application code */
    while (1) 
    {
		
		/*In case the sent character is a*/
		if (mspi_RecvByte_slave() == (char)'a')
		{
			/*Operate Motor 1*/
			hdc_motor1_operate_dir1();
		}
		
		/*In case the sent character is b*/
		else if (mspi_RecvByte_slave() == (char)'b')
		{
			/*Operate Motor 1 in reverse direction*/
			hdc_motor1_operate_dir2();
		}
		
		/*In case the sent character is c*/
		else if(mspi_RecvByte_slave() == (char)'c')
		{
			/*Stop Motor 1*/
			hdc_motor1_stop();
		}
		
		/*In case the sent character is d*/
		else if(mspi_RecvByte_slave() == (char)'d')
		{
			/*Operate Motor 2*/
			hdc_motor2_operate_dir1();
		}
		
		/*In case the sent character is e*/
		else if(mspi_RecvByte_slave() == (char)'e')
		{
			/*Operate Motor 2 in reverse direction*/
			hdc_motor2_operate_dir2();
		}
		
		/*In case the sent character is f*/
		else if(mspi_RecvByte_slave() == (char)'f')
		{
			/*Stop Motor 2*/
			hdc_motor2_stop();
		}
		
		/*In case the sent character is g*/
		else if(mspi_RecvByte_slave() == (char)'g')
		{
			/*Turn on LED 1*/
			hled_ledON(LED1);
		}
		
		/*In case the sent character is h*/
		else if(mspi_RecvByte_slave() == (char)'h')
		{
			/*Turn off LED 1*/
			hled_ledOFF(LED1);
		}
		
		/*In case the sent character is none of the above*/
		else
		{
			/*Do nothing*/
		}
		
		/*Delay for 1 second*/
		_delay_ms(1000);
		
    }
}

