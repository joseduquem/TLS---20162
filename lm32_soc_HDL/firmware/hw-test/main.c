/**
 * 
 */

#include "soc-hw.h"

int  main(){
	/*char a;
	for(a=1; a<8; a++){
		a=a+1;
		uart_putchar1(a);
		nsleep(101630);
	}
	isr_init();
	tic_init();
	irq_enable();
	
	uint32_t i;
	
	
	for(i=1; i<=10; i++) {
		uart_putchar1(i);    
		//i2c_write(ADDRESS_I2C,CH1,10);
		nsleep(101630);
	}*/
	
	uart_putstr1("AT+CIPMUX=0\r\n");
        nsleep(3016300);
	uart_putstr1("AT+CIPMODE=1\r\n");
	nsleep(3016300);
	uart_putstr1("AT+CIPSTART=\"TCP\",\"192.168.4.2\",80\r\n");
        nsleep(3016300);
	uart_putstr1("AT+CIPSEND\r\n");
        nsleep(3016300);
	char i=0;
	char a=0x30;
	for(i; i<=10; i++) {
	uart_putchar1(a);
	uart_putstr1("\r\n");
	nsleep(3016300);
	a++;
	}
}


/*inline void writeint(uint32_t val)
{
	uint32_t i, digit;o

	for (i=0; i<8; i++) {
		digit = (val & 0xf0000000) >> 28;
		if (digit >= 0xA) 
			uart_putchar('A'+digit-10);
		else
			uart_putchar('0'+digit);
		val <<= 4;
	}
}



char glob[] = "Global";

volatile uint32_t *p;
volatile uint8_t *p2;

extern uint32_t tic_msec;

int main()
{
	uint32_t aa,bb; 
for(;;)
	 uart_putchar('1');
	 uart_putchar('2');
	 uart_putchar('3');
	 uart_putchar('1');
	  aa=1;
	   prueba();
   uart_putchar('b');

   char test2[] = "Lokalerstr";
   char *str = test2;
   uint32_t i;

	// Say Hello!
	uart_putstr( "** Spike Test Firmware **\n" );

	// Initialize TIC
	isr_init();
	tic_init();
	irq_set_mask( 0x00000002 );
	irq_enable();

	// Say Hello!
	uart_putstr( "Timer Interrupt instelled.\n" );

	// Do some trivial tests
	uart_putstr( "Subroutine-Return Test: " );
	test();
	uart_putchar('\n');    

	uart_putstr( "Local-Pointer Test:" );
	for (;*str; str++) {
	   uart_putchar(*str);
	}
	uart_putchar('\n');    
	
	uart_putstr( "Global-Pointer Test:" );
	str = glob;
	for (;*str; str++) {
	   uart_putchar(*str);
	}
	uart_putchar('\n');    

	uart_putstr( "Stack Pointer : " );
	writeint(get_sp());
	uart_putchar('\n');    

	uart_putstr( "Global Pointer: " );
	writeint(get_gp());
	uart_putchar('\n');    

	uart_putstr( "Timer Test (1s): " );
	for(i=0; i<4; i++) {
		uart_putstr("tic...");    
		msleep(1000);
	}
	uart_putchar('\n');    

	uart_putstr( "Timer Interrupt counter: " );
	writeint( tic_msec );
	uart_putchar('\n');    

	int val = tic_msec;
	uart_putstr( "Shift: " );
	writeint( val );
	uart_putstr(" <-> ");    
	for(i=0; i<32; i++) {
		if (val & 0x80000000)
			uart_putchar( '1' );
		else
			uart_putchar( '0' );
			
		val <<= 1;
	}
	uart_putstr("\r\n");
*/
/*
	uart_putstr( "GPIO Test..." );
	gpio0->oe = 0x000000ff;
	for(;;) {
		for(i=0; i<8; i++) {
			uint32_t out1, out2;

			out1 = 0x01 << i;
			out2 = 0x80 >> i;
			gpio0->out = out1 | out2;

			msleep(100);
		}
	}
*/

/*
	uart_putstr("Entering Echo Test...\n");
	while (1) {
	   uart_putchar(uart_getchar());
	}
}
*/
