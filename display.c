#include <stdio.h>
#include <string.h>
#include "iodefine.h"
#include <stdint.h>
//#include "common.h"
//#include "config.h"
//#include "system.h"
#include "sfr.h"
#include "lcd_con.h"
#include "display.h"


extern unsigned char D1a[32] = "save the nature ";
extern unsigned char D1b[32] = "save the life   ";

extern unsigned char D2a[32] = "Hello  ";
extern unsigned char D2b[32] = "16563     ";

extern unsigned char D3a[32] = "'0804-0810:04*01";
extern unsigned char D3b[32] = " 9                           ";
extern unsigned char D3c[32] = "    0123  ";
extern unsigned char D3d[32] = "         R=";
extern unsigned char D3e[32] = "           001.5";

extern unsigned char D4a[32] = "EÅ˜ÅC ?ÅPA2     *02";
extern unsigned char D4b[32] = "+0000            ";

extern unsigned char D5a[32] = "ÅLÅ~- AaÅPÅC     *03";
extern unsigned char D5b[32] = ">Å}O     A?       ";


void display1(void)
{
	unsigned char n;
	unsigned char dsp_buf;
	
	lcd_l1(0);				
	        for (n=0 ;n<16 ;n++) {
		         dsp_buf = D1a[n];		//line 1
		         lcd_dout(dsp_buf);		//1data write
	}	
		    				
	//  write_string(1, 7, Line12); 
	    delay_msec(100);
	    write_string(1, 0, D2b); 
	    delay_msec(100);       
   
     
}
