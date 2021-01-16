/*
 * GPIO_Test.c
 *
 * Created: 06-Nov-20 6:10:15 PM
 * Author : Nouran Adel
 */ 


/* First trial*/

/*Library files*/
/*
#include "std_types.h"
#include "bit_math.h"
*/

/*Register files*/
/*
#include <avr/io.h>

#define F_CPU 16000000UL
#include "util/delay.h"
*/

/*LED pins*/
/*
#define LED0 2
#define LED1 7
#define LED2 3
*/

/*Button pins*/
/*
#define BUTT0 0
#define BUTT1 4
#define BUTT2 2
*/

/*
int main(void)
{*/
    /*DDRC = 0b10000100;
	DDRD = 0b00001000;
	
	PORTC = 0b10000100;
	PORTD = 0b00001000;*/
	
	/*Initialization code*/
	/*
	SET_BIT(DDRC, LED0);
	SET_BIT(DDRC, LED1);
	SET_BIT(DDRD, LED2);
	
	CLEAR_BIT(DDRB, BUTT0);
	CLEAR_BIT(DDRB, BUTT1);
	CLEAR_BIT(DDRD, BUTT2);*/
	
	/*while (1)
	{
	SET_BIT(PORTC, LED0);
	SET_BIT(PORTC, LED1);
	SET_BIT(PORTD, LED2);
	
	_delay_ms(1000);
	
	CLEAR_BIT(PORTC, LED0);
	CLEAR_BIT(PORTC, LED1);
	CLEAR_BIT(PORTD, LED2);
	
	_delay_ms(1000);
	}*/
	
	/*while (1)
	{
		TOGGLE_BIT(PORTC, LED0);
		TOGGLE_BIT(PORTC, LED1);
		TOGGLE_BIT(PORTD, LED2);
		
		_delay_ms(1000);
	}*/
	/*
	while(1){
		if(GET_BIT(PINB, BUTT0) || GET_BIT(PINB,BUTT1) || GET_BIT(PIND, BUTT2))
		{
			SET_BIT(PORTC, LED0);
			SET_BIT(PORTC, LED1);
			SET_BIT(PORTD, LED2);
		}
		else
		{
			CLEAR_BIT(PORTC, LED0);
			CLEAR_BIT(PORTC, LED1);
			CLEAR_BIT(PORTD, LED2);
		}
		
	      }
	
	
	return 0;
}*/

/************************************************************************/
/* Second Trial                                                                     */
/************************************************************************/

/*Library files*/

/*#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
//#include "MDIO_interface.h"
#include "HLED_interface.h"*/

/*Delay file*/
/*#define F_CPU 16000000UL
#include "util/delay.h"*/

/*LED pins*/
//#define LED0 PIN2
//#define LED1 PIN7
//#define LED2 PIN3


/*Button pins*/
/*#define BUTT0 PIN0
#define BUTT1 PIN4
#define BUTT2 PIN2


int main(void)
{*/
	
	//mdio_pinStatus(PORTC, LED0 | LED1, OUTPUT);	
	//mdio_pinStatus(PORTD, LED2, OUTPUT);
	
	
	/*hled_init(LED0);
	hled_init(LED1);
	hled_init(LED2);
	
	mdio_pinStatus(PORTB, BUTT0 | BUTT1, INPUT_FLOAT);
	mdio_pinStatus(PORTD, BUTT2, INPUT_FLOAT);*/
	
	/*while(1)
	{
		if(mdio_getPinValue(PORTB, BUTT0) || mdio_getPinValue(PORTB, BUTT1) || mdio_getPinValue(PORTD, BUTT2))
		{
			//mdio_setPinValue(PORTC, LED0 | LED1, HIGH);
			//mdio_setPinValue(PORTD, LED2, HIGH);
			hled_ledON(LED0);
			hled_ledON(LED1);
			hled_ledON(LED2);
		}
		else
		{
			//mdio_setPinValue(PORTC, LED0 | LED1, LOW);
			//mdio_setPinValue(PORTD, LED2, LOW);
			hled_ledOFF(LED0);
			hled_ledOFF(LED1);
			hled_ledOFF(LED2);
		}
		
		//mdio_togglePinValue(PORTC, LED0);
		//_delay_ms(1000);
		
		//hled_ledON(LED0);
		//_delay_ms(1000);
		//hled_ledOFF(LED0);
		//_delay_ms(1000);
	}
}*/
	
/************************************************************************/
/* Third Trial                                                                     */
/************************************************************************/

/*Library files*/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"


/*Delay file*/
#define F_CPU 16000000UL
#include "util/delay.h"*/

int main(void)
{
	mdio_pinStatus(PORTA)
}
