/**
 * 
 */

#include "soc-hw.h"

int  main(){
	isr_init();
	tic_init();
	irq_enable();
	
	init_wifi();
/*	char i=0;
	char a=0x30;
	for(i; i<=9; i++) {
		wifi_putchar(a);
		uart_putstr1("\r\n");
		nsleep(2016300);
		a++;
	}
*/
	char c;
	char d;
	char j;
	char k;
	//char l;
	//char m;
	//char n;
	//char o;
	int e;
	e=0;	
	do{	
		ReadChanel(0x00);	
		c=GetByteOne();
		ReadChanel(0x01);
		d=GetByteOne();
		ReadChanel(0x02);
		j=GetByteOne();
		ReadChanel(0x03);
		k=GetByteOne();
		uart_putchar(c);
		uart_putchar(d);
		uart_putchar(j);
		uart_putchar(k);
		uart_putchar(0);
		if(((c<=98)&(c>=82))&((d<=98)&(d>=80))&((j<=98)&(j>=82))&((k<=72)&(k>=58))){
		uart_putchar(1);
		wifi_putchar(0x61);
		}
		/*ReadChanel(0x02);
		j=GetByteOne();
		k=GetByteTwo();
		ReadChanel(0x01);	
		l=GetByteOne();
	        m=GetByteTwo();
		ReadChanel(0x00);
		n=GetByteOne();
		o=GetByteTwo();
		uart_putchar(c);
		c=0;
		uart_putchar(c);
		uart_putchar(d);
		d=0;
		uart_putchar(d);
		uart_putchar(1);
		uart_putchar(j);
		j=0;
		uart_putchar(j);
		uart_putchar(k);
		k=0;
		uart_putchar(k);
		uart_putchar(1);
		uart_putchar(l);
		l=0;
		uart_putchar(l);
		uart_putchar(m);
		m=0;
		uart_putchar(m);
		uart_putchar(1);
		uart_putchar(n);
		n=0;
		uart_putchar(n);
		uart_putchar(n);
		n=0;
		uart_putchar(n);
		uart_putchar(1);

//if((c==30)&((d==225)||(d==226)||(d==227)||(d==228))){
		//wifi_putchar(c);
		//j=0x34;
		//wifi_putchar(j);
		//c=0x30;
	        //uart_putchar(c);
		//wifi_putchar(c);
		//nsleep(201300);
		//wifi_putchar(d);
		//uart_putchar(d);
		//d=0x30;
                //uart_putchar(d);
		//wifi_putchar(d);
    //}
*/	}while(e==0);	

}
