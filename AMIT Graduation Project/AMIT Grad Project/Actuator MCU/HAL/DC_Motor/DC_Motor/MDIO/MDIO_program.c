/************************************************************************/
/* Name:    MDIO_interface.h                                              */
/* Author:  Nouran Adel                                                   */
/* Version: v1.0                                                          */
/* Description: This file contains DIO module logical program             */
/* Date: 7 November 2020                                                  */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*                        Functions' definitions                         */
/************************************************************************/

/*This function is responsible for setting pin or pins for a dedicated port*/
void mdio_pinStatus(u8_t port, u8_t pin, u8_t pin_status) /*pin: PIN0, PIN2 | PIN3, PIN1 | PIN5 | PIN4 | PIN3*/ /*0b00111010*/
{
	/*Switching over DIO ports*/
	switch(port)
	{
		/*In case of PORTA*/
		case PORTA:
			/*Switching over pin status*/
			switch(pin_status)
			{
				/*In case of output status*/
				case OUTPUT:
					/*Setting dedicated pins in DDR register*/
					MDIO_DDRA |= pin; /*DDRA = 0b01000010, 0b01111010*/
					//SET_BIT(DDRA, pin);
					break;
					
				/*In case of input status*/
				case INPUT_FLOAT:
				/*Clearing dedicated pins in DDR register*/
					MDIO_DDRA &= ~pin; /*DDRA = 0b11111111*/
					break;
					
				/*In case of input pull-up status*/
				case INPUT_PULLUP:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRA &= ~pin;
					/*Setting dedicated pins in DDR register*/
					MDIO_PORTA |= pin;
					break;
			}
			break;
			
		/*In case of PORTB*/
		case PORTB:
			/*Switching over pin status*/
			switch(pin_status)
			{
				/*In case of output status*/
				case OUTPUT:
					/*Setting dedicated pins in DDR register*/
					MDIO_DDRB |= pin; /*DDRA = 0b01000010, 0b01111010*/
					//SET_BIT(DDRA, pin);
					break;
					
				/*In case of input status*/
				case INPUT_FLOAT:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRB &= ~pin; /*DDRA = 0b11111111*/
					break;
					
				/*In case of input pull-up status*/
				case INPUT_PULLUP:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRB &= ~pin;
					/*Setting dedicated pins in DDR register*/
					MDIO_PORTB |= pin;
					break;
			}
			break;
			
		/*In case of PORTC*/
		case PORTC:
			/*Switching over pin status*/
			switch(pin_status)
			{
				/*In case of output status*/
				case OUTPUT:
					/*Setting dedicated pins in DDR register*/
					MDIO_DDRC |= pin; /*DDRA = 0b01000010, 0b01111010*/
					//SET_BIT(DDRA, pin);
					break;
					
				/*In case of input status*/
				case INPUT_FLOAT:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRC &= ~pin; /*DDRA = 0b11111111*/
					break;
					
				/*In case of input pull-up status*/
				case INPUT_PULLUP:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRC &= ~pin;
					/*Setting dedicated pins in DDR register*/
					MDIO_PORTC |= pin;
					break;
			}
			break;
			
		/*In case of PORTD*/
		case PORTD:
			/*Switching over pin status*/
			switch(pin_status)
			{
				/*In case of output status*/
				case OUTPUT:
					/*Setting dedicated pins in DDR register*/
					MDIO_DDRD |= pin; /*DDRA = 0b01000010, 0b01111010*/
					//SET_BIT(DDRA, pin);
					break;
					
				/*In case of input status*/
				case INPUT_FLOAT:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRD &= ~pin; /*DDRA = 0b11111111*/
					break;
					
				/*In case of input pull-up status*/
				case INPUT_PULLUP:
					/*Clearing dedicated pins in DDR register*/
					MDIO_DDRD &= ~pin;
					/*Setting dedicated pins in DDR register*/
					MDIO_PORTD |= pin;
					break;
			}
			break;
	}
	/*Return from this function*/
	return;
}

/*This function is responsible for setting a dedicated value for a pin or pins*/
void mdio_setPinValue(u8_t port, u8_t pin, u8_t pin_value)
{
	/*Switching over DIO ports*/
	switch(port)
	{
		/*In case of PORTA*/
		case PORTA:
			/*Switching over pin value*/
			switch(pin_value)
			{
				/*In case of HIGH value*/
				case HIGH:
					/*Setting dedicated pins in PORT register*/
					MDIO_PORTA |= pin; 
					break;
					
				/*In case of LOW value*/
				case LOW:
					/*Clearing dedicated pins in PORT register*/
					MDIO_PORTA &= ~pin; 
					break;
					
			}
			break;
			
		/*In case of PORTB*/
		case PORTB:
			/*Switching over pin value*/
			switch(pin_value)
			{
				/*In case of HIGH value*/
				case HIGH:
					/*Setting dedicated pins in PORT register*/
					MDIO_PORTB |= pin; 
					break;
					
				/*In case of LOW value*/
				case LOW:
					/*Clearing dedicated pins in PORT register*/
					MDIO_PORTB &= ~pin; 
					break;
					
			}
			break;
			
		/*In case of PORTC*/
		case PORTC:
			/*Switching over pin value*/
			switch(pin_value)
			{
				/*In case of HIGH value*/
				case HIGH:
					/*Setting dedicated pins in PORT register*/
					MDIO_PORTC |= pin; 
					break;
					
				/*In case of LOW value*/
				case LOW:
					/*Clearing dedicated pins in PORT register*/
					MDIO_PORTC &= ~pin; 
					break;
					
			}
			break;
			
		/*In case of PORTD*/
		case PORTD:
			/*Switching over pin value*/
			switch(pin_value)
			{
				/*In case of HIGH value*/
				case HIGH:
					/*Setting dedicated pins in PORT register*/
					MDIO_PORTD |= pin; 
					break;
					
				/*In case of LOW value*/
				case LOW:
				/*Clearing dedicated pins in PORT register*/
					MDIO_PORTD &= ~pin; 
					break;
					
			}
			break;
	}
	/*Return from this function*/
	return;
}

void mdio_togglePinValue(u8_t port, u8_t pin)
{
	/*Switching over DIO ports*/
	switch(port)
	{
		/*In case of PORTA*/
		case PORTA:
			/*Toggling dedicated pins values*/
			MDIO_PORTA ^= pin;
			break;
			
		/*In case of PORTB*/
		case PORTB:
			/*Toggling dedicated pins values*/
			MDIO_PORTB ^= pin;
			break;
			
		/*In case of PORTC*/
		case PORTC:
			/*Toggling dedicated pins values*/
			MDIO_PORTC ^= pin;
			break;
			
		/*In case of PORTD*/
		case PORTD:
			/*Toggling dedicated pins values*/
			MDIO_PORTD ^= pin;
			break;
	}
	/*Return from this function*/
	return;
}

/*This function is responsible for getting a dedicated pin value*/
u8_t mdio_getPinValue(u8_t port, u8_t pin)
{
	/*Local variable used to get a dedicated pin value*/
	u8_t pinValue = 0;
	
	/*Switching over DIO ports*/
	switch(port)
	{
		/*In case of PORTA*/
		case PORTA:
			/*Getting dedicated pin value*/
			//pinValue = GET_BIT(MDIO_PINA, pin);
			
			/*Anding PIN register value with pin number*/
			if(MDIO_PINA & pin) /*PINA = 0b10001000, pin = 0b00000001*/
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;
			
		/*In case of PORTB*/
		case PORTB:
			/*Getting dedicated pin value*/
			//pinValue = GET_BIT(MDIO_PINB, pin);
			
			/*Anding PIN register value with pin number*/
			if(MDIO_PINB & pin) /*PINA = 0b10001000, pin = 0b00000001*/
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;
			
		/*In case of PORTC*/
		case PORTC:
			/*Getting dedicated pin value*/
			//pinValue = GET_BIT(MDIO_PINC, pin);
			
			/*Anding PIN register value with pin number*/
			if(MDIO_PINC & pin) /*PINA = 0b10001000, pin = 0b00000001*/
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;
			
		/*In case of PORTD*/
		case PORTD:
			/*Getting dedicated pin value*/
			//pinValue = GET_BIT(MDIO_PIND, pin);
			
			/*Anding PIN register value with pin number*/
			if(MDIO_PIND & pin) /*PINA = 0b10001000, pin = 0b00000001*/
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;
	}
	/*Return the real value of the pin*/
	return pinValue;
}
