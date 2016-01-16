
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include<avr/io.h>                                    //standard AVR header
#include<util/delay.h>                                //delay header


#define LCD_PRT PORTC
#define LCD_DDR DDRC
#define LCD_PIN PINC

#define LCD_RS 2
#define LCD_EN 3


void lcdinit(void);
void lcd_gotoxy(unsigned char,unsigned char );
void lcdprint(char*);
void lcdcommand(unsigned char);
void delay_us(unsigned int);
void delay_ms(unsigned int );
void lcddata(unsigned char);




/*-----------------LCD INITIALIZATION FUNCTION------------------------*/


void lcdinit()

     {

      LCD_DDR=0XFF;
      LCD_PRT&=~(1<<LCD_EN);
      delay_us(2000);

      lcdcommand(0x33);
      delay_us(100);

      lcdcommand(0x32);
      delay_us(100);

      lcdcommand(0x28);
      delay_us(100);

      lcdcommand(0x0E);
      delay_us(100);

      lcdcommand(0x01);
      delay_us(2000);

      lcdcommand(0x06);
      delay_us(100);

     }


/*----------------------LCD COMMAND FUNCTION-------------------------------*/

void lcdcommand(unsigned char cmnd)

     {
     
      LCD_PRT=(LCD_PRT & 0x0F)|(cmnd & 0xF0);
      LCD_PRT&=~(1<<LCD_RS);
      LCD_PRT|=(1<<LCD_EN);

      delay_us(1);
      LCD_PRT&=~(1<<LCD_EN);

      delay_us(20);
      
      LCD_PRT=(LCD_PRT & 0X0F)|(cmnd<<4);
      LCD_PRT|=(1<<LCD_EN);
      
      delay_us(1);
      
      LCD_PRT&=~(1<<LCD_EN);
      
     }



/*-----------------DELAY FUNCTIONS----------------------------------*/

void delay_us(unsigned int d)
{
    _delay_us(d);
}

void delay_ms(unsigned int d)
{
    
    _delay_ms(d);
}


/*---------------LCD GOTOXY FUNTION--------------------------------*/


void lcd_gotoxy(unsigned char x,unsigned char y)
{
    
    unsigned char firstcharadr[]={0x80,0xC0,0x94,0xD4};
        lcdcommand(firstcharadr[y-1]+x-1);
        delay_us(100);
}

/*---------------LCD PRINT FUNCTION---------------------------------*/

void lcdprint(char *str)
{
    
    unsigned char i=0;
    while(str[i]!=0)
    {
        lcddata(str[i]);
        i++;
    }
    
}


/*-----------------LCD DATA FUNCTION---------------------------------*/


void lcddata(unsigned char data)

     {
     
      LCD_PRT =(LCD_PRT & 0X0F)|(data & 0XF0);
      LCD_PRT|=(1<<LCD_RS);
      LCD_PRT|=(1<<LCD_EN);
      
      delay_us(1);
      
      LCD_PRT&= ~(1<<LCD_EN);
      delay_us(20);

      LCD_PRT=(LCD_PRT & 0X0F)|(data<<4);
      LCD_PRT|=(1<<LCD_EN);

      delay_us(1);

      LCD_PRT&=~(1<<LCD_EN);

     }


