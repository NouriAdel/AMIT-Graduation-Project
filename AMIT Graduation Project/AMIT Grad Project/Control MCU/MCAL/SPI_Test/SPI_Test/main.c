
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_interface.h"
#include "MDIO_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	u8_t x = 0;
	mdio_pinStatus(PORTB, PIN4, OUTPUT);
	mdio_pinStatus(PORTB, PIN5, OUTPUT);
	mdio_pinStatus(PORTB, PIN6, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN7, OUTPUT);

	mspi_init(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);

    /* Replace with your application code */
    while (1) 
    {
		x = 'n';
		mspi_sendRecvByte(x);
		//mspi_sendStream((u8_t*)"Ahmed", 5);
		_delay_ms(1000);
    }
}

