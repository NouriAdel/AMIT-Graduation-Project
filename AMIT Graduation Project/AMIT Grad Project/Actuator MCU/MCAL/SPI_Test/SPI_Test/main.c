
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_interface.h"
#include "MDIO_interface.h"


#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	u8_t x = 0;
	
	mdio_pinStatus(PORTB, PIN4, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN5, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN6, OUTPUT);
	mdio_pinStatus(PORTB, PIN7, INPUT_FLOAT);
	
	mdio_pinStatus(PORTD, PIN2, OUTPUT);

	//mspi_init(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);
	mspi_init_slave(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);

    /* Replace with your application code */
    while (1) 
    {
		//x = 10;
		//mspi_sendRecvByte(&x);
		//mspi_sendStream((u8_t*)"Ahmed", 5);
		//x = mspi_RecvByte_slave();
		if (mspi_RecvByte_slave() == 'a')
		{
			mdio_setPinValue(PORTD, PIN2, HIGH);
		}
		else
		{
			mdio_setPinValue(PORTD, PIN2, LOW);
		}
		_delay_ms(1000);
    }
}

