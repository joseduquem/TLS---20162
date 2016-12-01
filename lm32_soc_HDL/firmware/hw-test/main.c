/**
 * 
 */

#include "soc-hw.h"

int  main(){
	isr_init();
	tic_init();
	irq_enable();
	
	init_wifi();

	char c; //meñique
	char d; //corazón
	char j; //índice
	char k; //pulgar
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
		if(((c>=81))&((d>=80))&((j>=80))&((k<=80))){
			wifi_putchar(0x61);//a
		}
		
		if(((c<=80))&((d>=80))&((j<=79))&((k<=80))){
			wifi_putchar(0x63);//c
		}
		if(((c<=80))&((d>=80))&((j>=80))&((k<=80))){
			wifi_putchar(0x64);//d
		}
		if(((c<=80))&((d<=79))&((j<=79))&((k<=80))){
			wifi_putchar(0x65);//e
		}
		if(((c>=81))&((d<=79))&((j>=80))&((k<=80))){
			wifi_putchar(0x66);//f
		}
		if(((c<=80))&((d<=79))&((j>=80))&((k<=80))){
			wifi_putchar(0x67);//g
		}
		if(((c>=81))&((d>=80))&((j<=79))&((k>=81))){
			wifi_putchar(0x69);//i
		}		
		if(((c>=81))&((d>=80))&((j<=79))&((k<=80))){
			wifi_putchar(0x6A);//j
		}
		if(((c>=81))&((d<=79))&((j>=80))&((k>=81))){
			wifi_putchar(0x6C);//l
		}
		if(((c<=80))&((d<=79))&((j<=79))&((k>=81))){
			wifi_putchar(0x6D);//m
		}
		if(((c<=80))&((d>=80))&((j<=79))&((k>=81))){
			wifi_putchar(0x6E);//n
		}
		if(((c>=81))&((d>=80))&((j>=80))&((k>=81))){
			wifi_putchar(0x6F);//o
		}
		if(((c<=80))&((d<=79))&((j>=80))&((k>=81))){
			wifi_putchar(0x70);//p
		}
		if(((c<=80))&((d>=80))&((j>=80))&((k>=81))){
			wifi_putchar(0x73);//s
		}
		if(((c>=81))&((d<=79))&((j<=79))&((k<=80))){
			wifi_putchar(0x74);//t
		}
		if(((c>=81))&((d<=79))&((j<=79))&((k>=81))){
			wifi_putchar(0x75);//u
		}
		
		
	}while(e==0);	

}
