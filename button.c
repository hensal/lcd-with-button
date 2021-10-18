#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sfr.h"
#include "button.h"

unsigned char before_opsw_id;
int count = 0;
int row = 1;
int col = 0;
int first = 1;
int second = 0;
int temp = 0;

extern unsigned char TITL12[32] = "ﾋｶｸ ｾｯﾃｲ     *02";
extern unsigned char TITL13[32] = "1               ";

extern unsigned char Line111[32] = "Hello,ggggg ";
extern unsigned char Line112[32] = "9   ";

extern unsigned char TITL99[32] = "Try your best 2021";
extern unsigned char TITL98[32] = "work hard   2053";

extern unsigned char Line1991[32] = "Hello  ";
extern unsigned char Line1112[32] = "16563     ";

extern unsigned char Data0[32] = "'0804-0810:04*01";
extern unsigned char Data1[32] = "Hello  ";
extern unsigned char Data2[32] = "3     ";

void display1(void)
{
	unsigned char n;
	unsigned char dsp_buf;
	
	lcd_l1(0);				
	        for (n=0 ;n<16 ;n++) {
		         dsp_buf = Data0[n];		
		         lcd_dout(dsp_buf);		
	}			   				

	    write_string(1, 0, Data2); 
	    delay_msec(100);   
	   //  write_string(1, 1, D2c);  	    
}


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




void IO_Init(void)
{
 //
}

void op_switich_in(void)
{
	unsigned char	opsw_id;
	
	opsw_id = op_swin_1d();		//スイッチデータ読込み

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
	
	P0 = P0 | 0x20;		//op_switch common on
	delay_micro(100);	//100microsec delay
	swid = P2 & 0x3F;
	P0 = P0 & 0xDF;		//op_switch common off
	
	return swid;
}

void dispset_titl1(void)
{
	unsigned char n;
	unsigned char dsp_buf;

	lcd_l1(0);				//1行目先頭アドレスセット
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL12[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}	
	lcd_l2(0);				//2行目先頭アドレスセット
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL13[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	   }
}

void dispset_titl2(void)
{
	unsigned char n;
	unsigned char dsp_buf;

	lcd_l1(0);				//1行目先頭アドレスセット
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL99[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}	
	lcd_l2(0);				//2行目先頭アドレスセット
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL98[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	   }
}

void op_switich_mdoef(void)
{	
	if (modef == 1) {		                          // when button is pressed       
              if (count == 0) {                                                      //   increment count and
	            count++;
		     delay_msec(100);
                     dispset_titl1();                     //   perform   function
	             modef=0;	         
        }  else if (count == 1) {                          // on second press
                     count++;                                           //   increment count and
	             delay_msec(100);
                      dispset_titl2();                                    //   perform another function,
	             modef=0;
        } else if (count == 2) {                          // on second press
	            lcd_cout(0x01);        
        } 
    } 
}



void op_switich_leftf(void)
{	
	if (leftf == 1) {		
		if( first>0) {
		set_cursor_position (first, second);	
		lcd_cout(0x0f);
		first = 1;
		second = second+1;
		leftf = 0;		
	    }	
	  } 
}

void op_switich_upf(void){	
      if (upf == 1) {   	 
	      temp = temp+1;	    
	      lcd_dout(temp);
	      set_cursor_position (1, 0);	
	      upf = 0;
	      }      
}

void op_switich_downf(void)
{		
	if (downf == 1){
		temp = temp -1;
		lcd_dout(temp);
		set_cursor_position (1, 0);
		downf = 0;
	    }	
}

void op_switich_rightf(void)
{	
	if (rightf == 1){
		first =1;
		second = second -1;
		set_cursor_position (first, second);	
		lcd_cout(0x0f);
		rightf =0;
	    }
}

void op_switich_setf(void)
{	
	if (setf == 1){
         set_cursor_position (1, 0);	
          lcd_cout(0x0f);
	    }	
}


void op_switich_setff(void)
{	
	if ((modef == 1)&&(rightf == 1)) {         
        set_cursor_position (1, 0);	
		lcd_cout(0x0f);
	    }	
	if ((modef == 1)&&(leftf == 1)) {      
	   set_cursor_position (1, 0);	
		lcd_cout(0x0f);
		//dispset_titl12345();
	}
}


int write_string(uint_fast8_t row, uint_fast8_t col, unsigned const char  *str) {
    int x,y;                                          	 
		  if (row)
		                {
			            col |= 0x40;				    
				    } 
				    col |= 0x80;
				    lcd_cout (col); 
	        for(y=0;Data2[y]!=0;y++) {
		temp= lcd_dout(Data2[y]);
		}                       
                      
		return 0;
       }


