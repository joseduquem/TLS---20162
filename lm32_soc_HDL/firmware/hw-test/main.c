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
	char c; //meñique
	char d; //corazón
	char j; //índice
	char k; //pulgar
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
		if(((c<=98)&(c>=82))&((d<=98)&(d>=82))&((j<=98)&(j>=82))&((k<=72)&(k>=58))){
		//uart_putchar(1);
			wifi_putchar(0x61);//a
		}
		if(((c<=72)&(c>=58))&((d<=72)&(d>=58))&((j<=72)&(j>=58))&((k<=98)&(k>=82))){
			wifi_putchar(0x62);//b
		}
		if(((c<=80)&(c>=74))&((d<=80)&(d>=74))&((j<=80)&(j>=74))&((k<=80)&(k>=74))){
			wifi_putchar(0x63);//c
		}
		if(((c<=80)&(c>=74))&((d<=80)&(d>=74))&((j<=72)&(j>=58))&((k<=80)&(k>=74))){
			wifi_putchar(0x64);//d
		}
		if(((c<=72)&(c>=58))&((d<=72)&(d>=58))&((j<=72)&(j>=58))&((k<=72)&(k>=58))){
			wifi_putchar(0x65);//e
		}
		if(((c<=72)&(c>=58))&((d<=72)&(d>=58))&((j<=80)&(j>=74))&((k<=72)&(k>=58))){
			wifi_putchar(0x66);//f
		}
		if(((c<=80)&(c>=74))&((d<=80)&(d>=74))&((j<=72)&(j>=58))&((k<=72)&(k>=58))){
			wifi_putchar(0x67);//g
		}
		if(((c<=80)&(c>=74))&((d<=72)&(d>=58))&((j<=72)&(j>=58))&((k<=72)&(k>=58))){
			wifi_putchar(0x68);//h
		}
		if(((c<=72)&(c>=58))&((d<=98)&(d>=82))&((j<=98)&(j>=82))&((k<=80)&(k>=74))){
			wifi_putchar(0x69);//i
		}
		if(((c<=72)&(c>=58))&((d<=98)&(d>=82))&((j<=98)&(j>=82))&((k<=80)&(k>=74))){
			wifi_putchar(0x6C);//l
		}
		if(((c<=98)&(c>=82))&((d<=80)&(d>=74))&((j<=72)&(j>=58))&((k<=72)&(k>=58))){
			wifi_putchar(0x6D);//m
		}
		if(((c<=80)&(c>=74))&((d<=72)&(d>=58))&((j<=72)&(j>=58))&((k<=80)&(k>=74))){
			wifi_putchar(0x6E);//n
		}
		if(((c<=72)&(c>=58))&((d<=80)&(d>=74))&((j<=80)&(j>=74))&((k<=80)&(k>=74))){
			wifi_putchar(0x6F);//o
		}
		if(((c<=72)&(c>=58))&((d<=80)&(d>=74))&((j<=72)&(j>=58))&((k<=72)&(k>=58))){
			wifi_putchar(0x70);//p
		}
		if(((c<=98)&(c>=82))&((d<=80)&(d>=74))&((j<=98)&(j>=82))&((k<=80)&(k>=74))){
			wifi_putchar(0x71);//q
		}
		if(((c<=98)&(c>=82))&((d<=72)&(d>=58))&((j<=72)&(j>=58))&((k<=80)&(k>=74))){
			wifi_putchar(0x72);//r
		}
		if(((c<=98)&(c>=82))&((d<=98)&(d>=82))&((j<=98)&(j>=82))&((k<=80)&(k>=74))){
			wifi_putchar(0x73);//s
		}
		if(((c<=98)&(c>=82))&((d<=80)&(d>=74))&((j<=80)&(j>=74))&((k<=72)&(k>=58))){
			wifi_putchar(0x74);//t
		}
		if(((c<=98)&(c>=82))&((d<=80)&(d>=74))&((j<=80)&(j>=74))&((k<=80)&(k>=74))){
			wifi_putchar(0x75);//u
		}
		if(((c<=98)&(c>=82))&((d<=72)&(d>=58))&((j<=98)&(j>=82))&((k<=80)&(k>=74))){
			wifi_putchar(0x76);//v
		}
		if(((c<=98)&(c>=82))&((d<=98)&(d>=82))&((j<=80)&(j>=74))&((k<=72)&(k>=58))){
			wifi_putchar(0x78);//x
		}
		if(((c<=72)&(c>=58))&((d<=98)&(d>=82))&((j<=98)&(j>=82))&((k<=72)&(k>=58))){
			wifi_putchar(0x79);//y
		}
		if(((c<=98)&(c>=82))&((d<=98)&(d>=82))&((j<=72)&(j>=58))&((k<=80)&(k>=74))){
			wifi_putchar(0x7A);//z
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
