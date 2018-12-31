#define F_CPU 16000000UL //16MHZ
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_ON PORTB|= (1<<PORTB5)
#define LED_OFF PORTB &= ~(1<<PORTB5)
#define LED_TOGGLE PINB |= (1<<PINB5)
#define SWITCH_PRESSED !(PINB & (1<<PINB7))

ISR(PCINT0_vect)
{
	if(!(PINB & (1<<PINB7)))
	{
			LED_ON;
	}
	else
	{
			LED_OFF;
	}

}

int main(void)
{
	DDRB |= (1<<DDB5);
	DDRB &= ~(1<<PDB7);

	PCMSK0 |= (1<<PCINT7); //Each PCINT[7:0] bit selects whether pin change interrupt is enabled on the corresponding I/O pin. If PCINT[7:0]
						   //is set and the PCIE0 bit in PCICR is set, pin change interrupt is enabled on the corresponding I/O pin.
	PCICR |= (1<<PCIE0);

	sei();
	while (1)
	{

	}
}
