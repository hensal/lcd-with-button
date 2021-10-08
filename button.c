#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sfr.h"
#include "button.h"

#define DEBOUNCE_TIME 100;

unsigned char		before_opsw_id;
int count = 0;
int lastCount = 0;
char *LCD_PORT = 0;
  int unit8_i,i;

extern unsigned char TITL12[32] = "save the money ";
extern unsigned char TITL13[32] = "enjoy the life   ";

void set_cursor_position (uint_fast8_t row, uint_fast8_t col)                                                 
	       {		 	 
		  if (row)
		                {
			            col |= 0x40;				    
				    } 
				    col |= 0x80;
				    lcd_cout (col); 				     	 
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

void op_switich_mdoef(void)
{	
	if (modef == 1){		                          // when button is pressed       
              if (count == 0) {                                                      //   increment count and
	            count++;
		    delay_msec(100);
                dispset_titl1();                     //   perform   function
	//	while(modef==1);	         
        }  else if (count == 1) {                          // on second press
               count++;                                           //   increment count and
	       delay_msec(100);
               lcd_cout(0x01);                                 //   perform another function,
	     //  while(modef==1);
        } else if (count == 2) {                          // on second press
	      count =0;
              set_cursor_position (1, 0);	
	      lcd_cout(0x0f);
        } 
    } 
}
void op_switich_upf(void)
{	
	     unsigned char   time = 6;
	     unsigned char     pos  = 1;
             unsigned char     line = 1;
	     
             pos++;
      if (upf == 1) {
           if(pos > 16 && line == 1 ) {        //if the position is end of the first line then change to the second line.
		   pos = 0;
		   line = 2;
      } else if (pos > 16 && line ==2) {            //if the position is end of the second line then change to the first line.
                   pos = 0;
		   line = 1;
	for(unit8_i = i; i < time; i++) {                   // This code is for speed up position selecting when the button is pressed longer.
	          delay_msec(100);
	}
	time -= 2;
	if (time < 2) time = 2;
	
                }
	    }	
}

void op_switich_downf(void)
{			

	if (downf == 1){
		lcd_cout(0x01);
	    }	
}

void op_switich_leftf(void)
{			

	if (leftf == 1){
		set_cursor_position (1, 0);	
		lcd_cout(0x0f);
	    }	
}

void op_switich_rightf(void)
{	
	if (rightf == 1){
		lcd_cout(0x01);
	    }	
}

void op_switich_setf(void)
{	
	if (setf == 1){
         set_cursor_position (1, 0);	
          lcd_cout(0x0f);
	    }	
}

// Clear display
void LCDClearDisplay(void) {
    LCDSendByte(0, ClearDisplay);
    delay_msec(2);
}

// Return cursor to home
void LCDReturnHome(void) {
    LCDSendByte(0, ReturnHome);
    delay_msec(2);
}

     // Send nibble to lcd
void LCDSendNibble(uint8_t nibble) {
    // Check nibbles bits and set PORT.
    *LCD_PORT = (unsigned)((nibble & 0b00000001) >> 0) ? (*LCD_PORT | (1 << LCD_D4)) : (*LCD_PORT & ~(1 << LCD_D4));
    *LCD_PORT = (unsigned)((nibble & 0b00000010) >> 1) ? (*LCD_PORT | (1 << LCD_D5)) : (*LCD_PORT & ~(1 << LCD_D5));
    *LCD_PORT = (unsigned)((nibble & 0b00000100) >> 2) ? (*LCD_PORT | (1 << LCD_D6)) : (*LCD_PORT & ~(1 << LCD_D6));
    *LCD_PORT = (unsigned)((nibble & 0b00001000) >> 3) ? (*LCD_PORT | (1 << LCD_D7)) : (*LCD_PORT & ~(1 << LCD_D7));
    
    // Send nibble to LCD.
    *LCD_PORT |= 1 << LCD_EN;  // E pin - LCD Enable
    delay_msec(1);
    *LCD_PORT &= ~(1 << LCD_EN);  // E pin - LCD Disable
    delay_msec(50); // min. 37us
}

// Send byte to lcd
void LCDSendByte(uint8_t reg, uint8_t byte) {
    *LCD_PORT = reg ? (*LCD_PORT | (1 << LCD_RS)) : (*LCD_PORT & ~(1 << LCD_RS));  // RS pin - Register Select
    
    *LCD_PORT &= ~(1 << LCD_RW);  // RW pin to write mode
    
    LCDSendNibble(byte >> 4);
    LCDSendNibble(byte & 0x0f);
}

// Set position
void LCDSetPos(uint8_t x, uint8_t y) {
    uint8_t addr;
    
    if(y == 2)
        addr = 0x40;
    else
        addr = 0;
    
    addr += x-1;
    
    LCDSendByte(0, 0x80 | addr);
}

// Print one character to lcd
void LCDPrintChar(uint8_t ch, uint8_t y, uint8_t x) {
    LCDSetPos(x, y);
    LCDSendByte(1, ch);
}


// Print string to lcd
void LCDPrintString(uint8_t *string, uint8_t y, uint8_t x) {
    // Set position
    // If x = 0, then print string to center
    if(x == 0) {
        for( i = 0; i < 17; i++, x++) {
            if(string[i] == '\0') break;
        }
        LCDSetPos((18-x)/2, y);
    } else {
        LCDSetPos(x, y);
    }
    
    // Write each char
    for( i = 0; i < 17; i++) {
        if(string[i] == '\0') break;
        LCDSendByte(1, string[i]);
    }
}

