
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MUART_interface.h"
#include "MUART_private.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "HBLUETOOTH_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	/*A variable used for storing data sent from Bluetooth*/
	u8_t recv_var = 0;
	
	/*Initialize UART*/
	muart_init(MUART_9600_BPS);
	
	/*Initialize SPI*/
	mspi_init(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);
	
    /* Replace with your application code */
    while (1) 
    {
		
		/*Send data from Bluetooth to Control MCU via UART*/
		muart_recvByte(&recv_var);
		
		/*Send data from Control MCU to Actuator MCU via SPI*/
		mspi_sendRecvByte(recv_var);
		
		/*Delay for 3 seconds*/
		_delay_ms(1000);
		
    }
}

