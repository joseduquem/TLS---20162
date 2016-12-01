#ifndef SPIKEHW_H
#define SPIKEHW_H

#define PROMSTART 0x00000000
#define RAMSTART  0x00000800
#define RAMSIZE   0x400
#define RAMEND    (RAMSTART + RAMSIZE)

#define RAM_START 0x40000000
#define RAM_SIZE  0x04000000

#define FCPU      100000000

#define UART_RXBUFSIZE 32


/****************************************************************************
 * Types
 */
typedef unsigned int  uint32_t;    // 32 Bit
typedef signed   int   int32_t;    // 32 Bit

typedef unsigned char  uint8_t;    // 8 Bit
typedef signed   char   int8_t;    // 8 Bit

/****************************************************************************
 * Interrupt handling
 */
typedef void(*isr_ptr_t)(void);

void     irq_enable();
void     irq_disable();
void     irq_set_mask(uint32_t mask);
uint32_t irq_get_mak();

void     isr_init();
void     isr_register(int irq, isr_ptr_t isr);
void     isr_unregister(int irq);

/****************************************************************************
 * General Stuff
 */
void     halt();
void     jump(uint32_t addr);


/****************************************************************************
 * Timer
 */
#define TIMER_EN     0x08    // Enable Timer
#define TIMER_AR     0x04    // Auto-Reload
#define TIMER_IRQEN  0x02    // IRQ Enable
#define TIMER_TRIG   0x01    // Triggered (reset when writing to TCR)

typedef struct {
	volatile uint32_t tcr0;
	volatile uint32_t compare0;
	volatile uint32_t counter0;
	volatile uint32_t tcr1;
	volatile uint32_t compare1;
	volatile uint32_t counter1;
} timer_t;

void msleep(uint32_t msec);
void nsleep(uint32_t nsec);

void prueba();
void tic_init();


/***************************************************************************
 * UART0
 */
#define UART_DR   0x01                    // RX Data Ready
#define UART_ERR  0x02                    // RX Error
#define UART_BUSY 0x10                    // TX Busy

typedef struct {
   volatile uint32_t ucr;
   volatile uint32_t rxtx;
} uart_t;
//UART0
void uart_init();
void uart_putchar(char c);
void uart_putstr(char *str);
char uart_getchar();
//UART1
void uart_init1();
void uart_putchar1(char c);
void uart_putstr1(char *str);
char uart_getchar1();

void init_wifi();
void wifi_putchar(char a);
char wifi_getchar();
int ok();

/***************************************************************************
 * I2C0
 */
#define txr 		0x03
#define rxr		0x03
#define cr		0x04
#define ADDRESS_I2C	0x68
#define CH1 		0x40 
#define CH2	        0x44
#define CH3	        0x48
#define CH4 		0x52

typedef struct {
   volatile uint32_t Busy;
   volatile uint32_t ByteReadedOne;
   volatile uint32_t ByteReadedTwo;
   volatile uint32_t ByteConfigurationOne;
   volatile uint32_t ByteConfigurationTwo;
   volatile uint32_t Start;
} i2c_t;

void ReadChanel(char ch);
char GetByteOne();
char GetByteTwo();

/***************************************************************************
 * Pointer to actual components
 */
extern i2c_t  *i2c0;
extern timer_t  *timer0;
extern uart_t   *uart0; 
extern uart_t   *uart1;
extern uint32_t *sram0; 

#endif // SPIKEHW_H
