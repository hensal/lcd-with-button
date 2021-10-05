//******************************************
//**           �t���\����\������ �@�@�@  **
//******************************************
//**includes **
//**
#include <stdio.h>
#include <string.h>
#include "iodefine.h"
//#include "common.h"
//#include "config.h"
//#include "system.h"
#include "sfr.h"
#include "lcd_con.h"

/**********************************************************************
*** define�@(������`�j
**********************************************************************/
extern unsigned char TITL0[32] = "DISPLAYtest 2021";
extern unsigned char TITL1[32] = "work hard   2053";

extern unsigned char TITL2[32] = "save the nature ";
extern unsigned char TITL3[32] = "save the life   ";

extern unsigned char TITL10[32] = "'0804-0810:04*01";
extern unsigned char TITL11[32] = "H =+0123            ";

extern unsigned char TITL112[32] = "˶� ��ò     *02";
extern unsigned char TITL113[32] = "+0000            ";

extern unsigned char TITL14[32] = "��- ����     *03";
extern unsigned char TITL15[32] = ">��     ż       ";

//*****************************************
void dispset_titl(void)
{
	unsigned char n;
	unsigned char dsp_buf;

	lcd_l1(0);				//1�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL2[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}	
	lcd_l2(0);				//2�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL3[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	   }
	
	delay_msec(1000);
	lcd_cout(0x01);	
	
	lcd_l1(0);				//1�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL0[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}	
	lcd_l2(0);				//2�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL1[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	}
	
	delay_msec(1000);
	lcd_cout(0x01);	
	
	lcd_l1(0);				//1�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL10[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}	
	lcd_l2(0);				//2�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL11[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	}
	delay_msec(1000);
	lcd_cout(0x01);	
	
	lcd_l1(0);				//1�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL112[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}	
	lcd_l2(0);				//2�s�ڐ擪�A�h���X�Z�b�g
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL113[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	}
	
	}

void dispset_count(void)
{
      delay_msec(100);	
}

//****************************************
//**�@LCD������
//
void lcd_init(void)
{
	P7 = 0x00;		//E=0,RS=0
//	
	P7 = 0x03;
	P7 = 0x23;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x03;		//E=0,RS=0
	delay_msec(5);
//
	P7 = 0x23;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x03;		//E=0,RS=0
	delay_msec(5);
//
	P7 = 0x23;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x03;		//E=0,RS=0
	delay_msec(5);
//
	P7 = 0x02;		//4bit�ް����ݒ�
	P7 = 0x22;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x02;		//E=0,RS=0
	delay_msec(5);
//** ��������4�ޯ��ް���
	lcd_cout(0x02);		                          //for 4-bit lcd intialization
	delay_msec(5);
	lcd_cout(0x28);		
	delay_msec(5);
	lcd_cout(0x0C);
	delay_msec(5);    
	lcd_cout(0x06);
	delay_msec(5); 
	lcd_cout(0x01);
	delay_msec(5);  
	lcd_cout(0x80);
	delay_msec(5);  
			
}

//*****************************************
//** 1�s�ڱ��ڽ���
//** col_1 = ��
//**
void lcd_l1(unsigned char col1)
{
	unsigned char posit1;
//
	posit1 = col1 & 0x0F;	//��̍ő�l��16
	posit1 = posit1 + 0x80;	//1�s���ޯĒǉ�
	lcd_cout(posit1);
	delay_msec(5);
}

//*****************************************
//** 2�s�ڱ��ڽ���
//**
void lcd_l2(unsigned char col2)
{
	unsigned char posit2;

	posit2 = col2 & 0x4F;	//��̍ő�l��16
	posit2 = posit2 + 0xC0;	//2�s���ޯĒǉ�
	lcd_cout(posit2);
	delay_msec(5);
}
//*****************************************
//** ��׸�LCD�@���۰ٺ��ޏo��
//
void lcd_cout(unsigned char ccod)
{
	unsigned char ccod_msb;
	unsigned char ccod_lsb;

	ccod_msb = ccod / 0x10;
	ccod_lsb = ccod & 0x0F;
//
	P7 = ccod_msb;		//E=0,RS=0 + MSB
	
	P7 = ccod_msb | 0x20;	//E=1,RS=0
	delay_micro(2);
	P7 = ccod_msb;		//E=0,RS=0
//
	delay_micro(2);
//
	P7 = ccod_lsb;		//E=0,RS=0 + LSB
	
	P7 = ccod_lsb | 0x20;	//E=1,RS=0
	delay_micro(2);
	P7 = ccod_lsb;		//E=0,RS=0
	delay_micro(50);
}
//****************************************
//** ��׸�LCD�@�ް����ޏo��
//
void lcd_dout(unsigned char dcod)
{
	unsigned char dcod_msb;
	unsigned char dcod_lsb;

	dcod_msb = dcod / 0x10;
	dcod_lsb = dcod & 0x0F;
//
	P7 = dcod_msb | 0x10;	//E=0,RS=1 + MSB
	
	P7 = dcod_msb | 0x30;	//E=1,RS=1
	delay_micro(2);
	P7 = dcod_msb | 0x10;	//E=0,RS=1
//
	delay_micro(2);
//
	P7 = dcod_lsb | 0x10;	//E=0,RS=1 + LSB
	
	P7 = dcod_lsb | 0x30;	//E=1,RS=1
	delay_micro(2);
	P7 = dcod_lsb | 0x10;	//E=0,RS=1
	delay_micro(50);
//
}
//*****************************************
//** ϲ�ەb�x��
void delay_micro(unsigned int icnt)
{
	unsigned int del_cnt;

	for (del_cnt=0;del_cnt<icnt;del_cnt++){
	
		        NOP();
 			NOP();
			NOP();
			NOP();
			NOP();					
	              }
                  }
//******************************************
//** �ؕb�x��
void delay_msec(unsigned int icnt)
{
	unsigned int del_cnt;

	for (del_cnt=0;del_cnt<icnt;del_cnt++){
//		wdt_rst();      
               WDTE = 0xAC;
		delay_micro(1000);
		 
	}
}

