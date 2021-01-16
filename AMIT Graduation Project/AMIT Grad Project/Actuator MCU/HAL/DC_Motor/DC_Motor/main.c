
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	
	hdc_motor_init();
	hdc_motor_operate_dir1();
	
    /* Replace with your application code */
    while (1) 
    {
		//hdc_motor_operate();
		
		//_delay_ms(3000);
		
		hdc_motor_reverse();
		
		_delay_ms(1000);
    }
	return 0;
}

