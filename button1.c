#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sfr.h"
#include "button.h"

unsigned char before_opsw_id;

extern unsigned char TITL12[32] = "Ë¶¸ ¾¯Ã²     *02";
extern unsigned char TITL13[32] = "1               ";

extern unsigned char Line111[32] = "Hello,ggggg ";
extern unsigned char Line112[32] = "9   ";

extern unsigned char TITL99[32] = "Try your best 2021";
extern unsigned char TITL98[32] = "work hard   2053";

extern unsigned char Line1991[32] = "Hello  ";
extern unsigned char Line1112[32] = "16563     ";

extern unsigned char Data0[32] = "'0804-0810:04*01";
extern unsigned char Data1[32] = "Hello  ";
extern unsigned char Data2[32] = "t= ";
extern unsigned char Data3[32] = "3 ";
extern unsigned char Data4[32] = "2 ";
extern unsigned char Data5[32] = "4                ";

int counter = 0;
int count = 0;
int first = 1;
int second = 2;
int temp = 0;
int temp1 = 0;
int temp2 = 0;
int value = 0;

int set_cursor_position (uint_fast8_t row, uint_fast8_t col)                                                 
	       {		 	 
		  if (row)
		                {
			            col |= 0x40;				    
				    } 
				    col |= 0x80;
				    lcd_cout (col); 	
				    return 0;
  }  	       
	       
int display1(void)
{
	unsigned char n;
	unsigned char dsp_buf;
	unsigned char dsp_buf1;
	
	lcd_l1(0);				
	        for (n=0 ;n<16 ;n++) {
		         dsp_buf = Data0[n];		
		         lcd_dout(dsp_buf);		
	           }  
		
		   lcd_l2(0x80);
		   for (n=0 ;n<16 ;n++) {
		         dsp_buf = Data2[n];		
		         lcd_dout(dsp_buf);	
		   } 
		    
		   lcd_l2(0x82);
		   for (n=0 ;n<16 ;n++) {
	                 dsp_buf = Data3[n];		
		         temp =  lcd_dout(dsp_buf);	
		   } 
		   
		   lcd_l2(0x83);
		   for (n=0 ;n<16 ;n++) {
		        dsp_buf = Data4[n];		
		        temp1=  lcd_dout(dsp_buf);	
		   } 
		   
		    lcd_l2(0x84);
		   for (n=0 ;n<16 ;n++) {
		        dsp_buf = Data5[n];		
		        temp2 = lcd_dout(dsp_buf);	
		   }        
	return 0;
}

void op_switich_upf(void){		          
        if (upf == 1) {		       
		          set_cursor_position (1, 2);
	         if (temp >= 47 && temp < 57) {			    
	                 temp = temp+1;	     
	                 lcd_dout(temp);
	                set_cursor_position (1, 2);
	                upf = 0;	 
	      }  
	      else {
		       set_cursor_position(1,3);
	      if (upf ==1) {
	      if (temp1 >= 47 && temp1 < 57) {
	              temp1 = temp1 +1;
	              lcd_dout(temp1);
	              set_cursor_position(1,3);
	              upf = 0;
	          }
	        }
	     } 	
	}      	     
}

void op_switich_downf(void)
{		
	if (downf == 1) {
		 if (temp >= 49 ) {
		  temp = temp -1;
		  value = lcd_dout(temp);
		  set_cursor_position (1, 2);
		  downf = 0;
	    }	
	}
}

void op_switich_setf(void)
{	
	    if (setf == 1) {		    
                set_cursor_position (1, 2);
	        lcd_cout(0x0f);
	        setf = 0;
	 	     }
}

void op_switich_in(void)
{
	unsigned char	opsw_id;
	
	opsw_id = op_swin_1d();		   

	if (opsw_id == before_opsw_id){
		if ((opsw_id & 0x01) == 0) modef = 1;
		if ((opsw_id & 0x02) == 0) upf = 1;
		if ((opsw_id & 0x04) == 0) downf = 1;
		if ((opsw_id & 0x08) == 0) leftf = 1;
		if ((opsw_id & 0x10) == 0) rightf = 1;
		if ((opsw_id & 0x20) == 0) setf = 1;
	}	
	before_opsw_id = opsw_id;		
}	

unsigned char op_swin_1d(void)
{
	unsigned char swid;
	
	P0 = P0 | 0x20;		       //op_switch common on
	delay_micro(100);	               //100microsec delay
	swid = P2 & 0x3F;
	P0 = P0 & 0xDF;		       //op_switch common off
	
	return swid;
}

void dispset_titl1(void)
{
	unsigned char n;
	unsigned char dsp_buf;

	lcd_l1(0);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL12[n];		
		lcd_dout(dsp_buf);		     
	}	
	lcd_l2(0);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL13[n];		
		lcd_dout(dsp_buf);		
	   }
}

void dispset_titl2(void)
{
	unsigned char n;
	unsigned char dsp_buf;

	lcd_l1(0);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL99[n];		
		lcd_dout(dsp_buf);		
	}	
	lcd_l2(0);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL98[n];		
		lcd_dout(dsp_buf);		
	   }
}

void op_switich_mdoef(void)
{	
	if (modef == 1) {		                                             // when button is pressed       
              if (count == 0) {                                                      //   increment count and
	            count++;
		     delay_msec(100);
                     dispset_titl1();                                                 //   perform   function
	             modef=0;	         
        }  else if (count == 1) {                                                 // on second press
                     count++;                                                          //   increment count and
	             delay_msec(100);
                      dispset_titl2();                                                //   perform another function,
	             modef=0;
        } else if (count == 2) {                                                  // on second press
	            lcd_cout(0x01);        
        } 
    } 
}

void op_switich_rightf(void)
{	
	if (rightf == 1) {		
		if( second>1 && second <=4 ) {
		lcd_cout(0x0f);
		first = 1;
		second = second+1;	
		if(second	>4) second =2;
		set_cursor_position (first,second);	
	      }	
		rightf = 0;	
     	} 
}

void op_switich_leftf(void)
{	
	if (leftf == 1){
		if ( second>1 && second <=4){
		lcd_cout(0x0f);
		first =1;
		second = second -1;
		if(second	<2) second =4;
		set_cursor_position (first, second);	
	    }
	   leftf =0;
	}
}
