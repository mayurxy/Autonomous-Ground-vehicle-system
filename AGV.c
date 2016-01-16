/*
 * AGV.c
 *
 * Created: 05/11/2013 17:01:06
 *  Author: mayur
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "mydefs.h"
void left_motor(signed int i)
{
  if (i == 1)
{
	set(PORTB,4);
	clr(PORTB,2);
}
else if (i == -1)
{
	set(PORTB,2);
	clr(PORTB,4);
}
else 
{
	clr(PORTB,2);
	clr(PORTB,4);
	
}	
}	
void right_motor(signed int j)
{if (j == 1)
{
	set(PORTB,0);		
	clr(PORTB,1);
}
else if (j == -1)
{
	clr(PORTB,0);		
	set(PORTB,1);
}
 else
 {
	 clr(PORTB,0);		
	clr(PORTB,1);
 }
	
}
 
int main(void)
{  
uint8_t sensor;
    DDRA=0;
	DDRB=255;
	DDRD=255;
// 	while(1)
// 	{
// 	left_motor(1);
// 	right_motor(1);
// 	_delay_ms(10000);
// 	left_motor(-1);
// 	right_motor(-1);
// 	_delay_ms(10000);
// 	left_motor(0);
// 	right_motor(1);
// 	_delay_ms(10000);
// 	left_motor(1);
// 	right_motor(0);
// 	_delay_ms(60000);		
// 	}
	//DDRD=255;
	//PORTD=255;
// 	_delay_ms(10);
	while(1)
	{
sensor=PINA;
// if (sensor == 0b01111111)
// {left_motor(-1);
// 	right_motor(1);
// }
// else if (sensor == 0b10111111)
// {
// 	left_motor(1);
// 	right_motor(-1);
// }
// else if (sensor == 0b00111111)
// {
// 	left_motor(0);
// 	right_motor(0);
// 	
// }
// 
// if (PINA0==0)
// {
// 	left_motor(1);
// 	
// }
// else if (PINA1==0)
// {
// 	right_motor(1);
// }
// else if ((PINA0==0)||(PINA1==0))
// {
// 	PORTD=255;
// }
// else if (PINA2==0)
// {
// 	PORTD=255;
// }
//  
	switch(sensor)
	{
		
		case 0X7F : left_motor(0);
							right_motor(0);
	
	break;
	
		case 0XBF : left_motor(0);
						   right_motor(0);
		break;
	
		case 0b11011111 : left_motor(1);
							right_motor(0);
		break;
	
		case 0b11101111 :left_motor(1);
							right_motor(0);
		break;
	
		case 0b11001111 :left_motor(1);
							right_motor(-1);
		break;
	
		case 0b11110111 :left_motor(0);
	 						right_motor(1);
		break;
	
		case 0b11111011 :left_motor(0);
						right_motor(1);
		break;
	
		case 0b11110011 : left_motor(-1);
						right_motor(1);
		break;
	
		case 0b10011111 : left_motor(1);
						right_motor(1);
		break;
	
// 		case 0b00011111 : left_motor(0);
// 						right_motor(0);
// 		break;
// 	
	
		
		case 0b10001111 : left_motor(1);
						right_motor(-1);
		break;
	
		case 0b01110011 : left_motor(-1);
						right_motor(1);
	break;
	
		case 0b10011011 : left_motor(1);
		right_motor(-1);
	break;
	
		case 0b10010111 : left_motor(1);
		right_motor(0);
	break;
	
		case 0b10010011 :  left_motor(0);
		right_motor(0);
	break;
	
		case 0b10001011 :left_motor(1);
		right_motor(-1);
	break;
	
		case 0b10000111 : left_motor(1);
		right_motor(0);
	break;
	
		case 0b10000011 : left_motor(0);
		right_motor(0);
	break;
	
		case 0b00000011 : left_motor(0);
		right_motor(0);
	break;
	
		case 0b01111011 :left_motor(0) ;
		right_motor(1);
	break;
	
		case 0b00111011 : left_motor(0);
		right_motor(0);
	
	break;
	
		case 0b0011111 :left_motor(0);
		right_motor(0);
	break;
		case 0b00001011 : left_motor(0);
		right_motor(0);
	break;
		case 0b01001011 : left_motor(-1);
		right_motor(1);
	break;
		case 0b00011011 : left_motor(0);
		right_motor(0);
	break;
		default:left_motor(1);
		right_motor(1);
	break;
				
		
		
		//sensor=255;
		
	}		
		
	
	
	
		
	}

		return 0;
}