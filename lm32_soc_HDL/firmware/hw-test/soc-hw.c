#include "soc-hw.h"

uart_t  *uart0  = (uart_t *)   	0x20000000;
uart_t  *uart1  = (uart_t *)  	0x30000000;
timer_t *timer0 = (timer_t *)   0x40000000;
i2c_t   *i2c0   = (i2c_t *)    	0x50000000;

isr_ptr_t isr_table[32];

void tic_isr();
/***************************************************************************
 * IRQ handling
 */
void isr_null()
{
}

void irq_handler(uint32_t pending)
{
	int i;

	for(i=0; i<32; i++) {
		if (pending & 0x01) (*isr_table[i])();
		pending >>= 1;
	}
}

void isr_init()
{
	int i;
	for(i=0; i<32; i++)
		isr_table[i] = &isr_null;
}

void isr_register(int irq, isr_ptr_t isr)
{
	isr_table[irq] = isr;
}

void isr_unregister(int irq)
{
	isr_table[irq] = &isr_null;
}

/***************************************************************************
 * TIMER Functions
 */
void msleep(uint32_t msec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000)*msec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}

void nsleep(uint32_t nsec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000000)*nsec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}


uint32_t tic_msec;

void tic_isr()
{
	tic_msec++;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;
}

void tic_init()
{
	tic_msec = 0;

	// Setup timer0.0
	timer0->compare0 = (FCPU/10000);
	timer0->counter0 = 0;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;

	isr_register(1, &tic_isr);
}


/***************************************************************************
 * UART0 Functions
 */
void uart_init()
{
	//uart0->ier = 0x00;  // Interrupt Enable Register
	//uart0->lcr = 0x03;  // Line Control Register:    8N1
	//uart0->mcr = 0x00;  // Modem Control Register

	// Setup Divisor register (Fclk / Baud)
	//uart0->div = (FCPU/(57600*16));
}

char uart_getchar()
{   
	while (! (uart0->ucr & UART_DR)) ;
	return uart0->rxtx;
}

void uart_putchar(char c)
{
	while (uart0->ucr & UART_BUSY) ;
	uart0->rxtx = c;
}

void uart_putstr(char *str)
{
	char *c = str;
	while(*c) {
		uart_putchar(*c);
		c++;
	}
}

/***************************************************************************
* UART1 Functions
 */
void uart_init1()
{
	//uart1->ier = 0x00;  // Interrupt Enable Register
	//uart1->lcr = 0x03;  // Line Control Register:    8N1
	//uart1->mcr = 0x00;  // Modem Control Register

	// Setup Divisor register (Fclk / Baud)
	//uart1->div = (FCPU/(57600*16));
}

char uart_getchar1()
{   
	while (! (uart1->ucr & UART_DR)) ;
	return uart1->rxtx;
}

void uart_putchar1(char c)
{
	while (uart1->ucr & UART_BUSY) ;
	uart1->rxtx = c;
}

void uart_putstr1(char *str)
{
	char *c = str;
	while(*c) {
		uart_putchar1(*c);
		c++;
	}
}

/***************************************************************************
 * WIFI ESP8266 Functions
 */

void init_wifi(){ //configurar el modulo como estación con puerto 80
	//uart_putstr1("AT+RST\r\n");
	//nsleep(2016300);
	//int c = 0;
	//while(c==0){
		uart_putstr1("AT+CIPMUX=0\r\n");
		//c = ok();
		nsleep(2016300);
	//}
	//c = 0;
	//while (c==0){
		uart_putstr1("AT+CIPMODE=1\r\n");
		//c = ok();
		nsleep(2016300);
	//}
	//c = 0;
	//while (c==0){
		uart_putstr1("AT+CIPSTART=\"TCP\",\"192.168.4.2\",1234\r\n");
		//c = ok();
		nsleep(2016300);
		uart_putstr1("AT+CIPSEND\r\n");
		nsleep(2016300);
	//}
}

void wifi_putchar(char a){
	//int c = 0; 	  
	//while(c == 0){
		uart_putchar1(a);
		//c = ok();
	//}
}

char wifi_getchar(){
	char c='\n';
	int i=0;
	for(i=0;i<20;i++){
		c = uart_getchar1();
		if (c ==':'){
			c = uart_getchar1();
			return c;
			break;
		}
	}
	return '\n';

}

int ok(){
	int i=0;
	char a;
	for(i=0;i<30;i++){
		a=uart_getchar1();
		if(a=='K'){
			return 1;
		}
	}
	return 0;

}

/*********************************************************
I2C 
*/
/*
StartCond"BOTH"
Write"BOTH"
Potiner"BOTH"
Read"BOTH"
Stop"BOTH"
ByteReaded"READ"
ByteToWrite"WRITE
*/

void ReadChanel(char ch){
	switch(ch){
	   case 0x00:
		i2c0->ByteConfigurationOne=0xC3;
	   break;
	   case 0x01:
		i2c0->ByteConfigurationOne=0xD3;
	   break;
	   case 0x02:
		i2c0->ByteConfigurationOne=0xE3;
	   break;
	   case 0x03:
		i2c0->ByteConfigurationOne=0xF3;
	   break;
	   default:
		i2c0->ByteConfigurationOne=0xC3;
	   break;
	}
	i2c0->ByteConfigurationTwo=0X83;//FS 4.096 volts although this is more than electrical especifications,there never be more than 3.6
	i2c0->Start=0x01;
	while((i2c0->Busy)==0x01);
}


char GetByteOne(){
	return i2c0->ByteReadedOne;
}
char GetByteTwo()
{
	return i2c0->ByteReadedTwo;
}
