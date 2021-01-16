
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MUART_interface.h"
#include "MUART_private.h"
#include "MDIO_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	u8_t recv_var = 0;
	
	mdio_pinStatus(PORTD, PIN0, INPUT_FLOAT);
	mdio_pinStatus(PORTD, PIN1, OUTPUT);
	mdio_pinStatus(PORTD, PIN2, OUTPUT);
	
	muart_init(MUART_9600_BPS);
	
    /* Replace with your application code */
    while (1) 
    {
		//muart_sendByte('a');
		//_delay_ms(1000);
		
		/*muart_recvByte(&recv_var);
		
		if(recv_var == 'a')
		{
			mdio_setPinValue(PORTD, PIN2, HIGH);
		}
		else
		{
			mdio_setPinValue(PORTD, PIN2, LOW);
		}*/
		
		muart_sendStream((u8_t*)"Nouran", 6);
		//muart_sendStream((u8_t*)"Nouran /r/n", 8);
		_delay_ms(1000);
		muart_sendByte('\r');
		muart_sendByte('\n');
		//muart_sendStream("\r\n",2)
    }
	
	return 0;
	
}

