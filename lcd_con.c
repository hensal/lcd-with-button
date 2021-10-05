//******************************************
//**           液晶表示器表示制御 　　　  **
//******************************************
//**includes **
//**
#include <stdio.h>
#include <string.h>
#include "iodefine.h"
//#include "common.h"
//#include "config.h"
//#include "system.h"
//#include "sfr.h"
#include "lcd_con.h"

/**********************************************************************
*** define　(文字定義）
**********************************************************************/
extern unsigned char TITL0[16] = "DISPLAYtest 2021";
extern unsigned char TITL1[16] = "    ｶｳﾝﾀｰ =     ";

//*****************************************
void dispset_titl(void)
{
	unsigned char n;
	unsigned char dsp_buf;

	lcd_l1(0);				//1行目先頭アドレスセット
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL0[n];		//line 1
		lcd_dout(dsp_buf);		//1data write
	}
	
	lcd_l2(0);				//2行目先頭アドレスセット
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL1[n];		//line 2
		lcd_dout(dsp_buf);		//1data write
	}
}
//****************************************
//**
void dispset_count(void)
{
	
	delay_msec(100);
	dpcnt[0]++;
	if (dpcnt[0] > 9){
		dpcnt[0] = 0;
		dpcnt[1]++;
	}
	if (dpcnt[1] > 9){
		dpcnt[1] = 0;
		dpcnt[2]++;
	}
	if (dpcnt[2] > 9){
		dpcnt[2] = 0;
		dpcnt[3]++;
	}
	if (dpcnt[3] > 9){
		dpcnt[3] = 0;
	}
	lcd_cout(0xCC);
	lcd_dout(dpcnt[3] + 0x30);
	lcd_dout(dpcnt[2] + 0x30);
	lcd_dout(dpcnt[1] + 0x30);
	lcd_dout(dpcnt[0] + 0x30);
}

//****************************************
//**　LCD初期化
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
	P7 = 0x02;		//4bitﾃﾞｰﾀ長設定
	P7 = 0x22;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x02;		//E=0,RS=0
	delay_msec(5);
//** ここから4ﾋﾞｯﾄﾃﾞｰﾀ長
	lcd_cout(0x28);		//ﾌｧﾝｸｼｮﾝｾｯﾄ	
	delay_msec(5);
	lcd_cout(0x08);		//表示ｵﾌ	
	delay_msec(5);
	lcd_cout(0x01);		//表示ｸﾘﾔｰ	
	delay_msec(5);
	lcd_cout(0x06);		//ｴﾝﾄﾘｰﾓｰﾄﾞｾｯﾄ	
	delay_msec(5);
	lcd_cout(0x0E);		//表示on、ｶｰｿﾙon	
	delay_msec(5);
}

//*****************************************
//** 1行目ｱﾄﾞﾚｽｾｯﾄ
//** col_1 = 列
//**
void lcd_l1(unsigned char col1)
{
	unsigned char posit1;
//
	posit1 = col1 & 0x0F;	//列の最大値＝16
	posit1 = posit1 + 0x80;	//1行目ﾋﾞｯﾄ追加
	lcd_cout(posit1);
	delay_msec(5);
}

//*****************************************
//** 2行目ｱﾄﾞﾚｽｾｯﾄ
//**
void lcd_l2(unsigned char col2)
{
	unsigned char posit2;

	posit2 = col2 & 0x0F;	//列の最大値＝16
	posit2 = posit2 + 0xC0;	//2行目ﾋﾞｯﾄ追加
	lcd_cout(posit2);
	delay_msec(5);
}
//*****************************************
//** ｷｬﾗｸﾀLCD　ｺﾝﾄﾛｰﾙｺｰﾄﾞ出力
//
void lcd_cout(unsigned char ccod)
{
	unsigned char ccod_msb;
	unsigned char ccod_lsb;

	ccod_msb = ccod / 0x10;
	ccod_lsb = ccod & 0x0F;
//
	P7 = ccod_msb;		//E=0,RS=0 + MSB
	delay_micro(2);
	P7 = ccod_msb | 0x20;	//E=1,RS=0
	delay_micro(2);
	P7 = ccod_msb;		//E=0,RS=0
//
	delay_micro(2);
//
	P7 = ccod_lsb;		//E=0,RS=0 + LSB
	delay_micro(2);
	P7 = ccod_lsb | 0x20;	//E=1,RS=0
	delay_micro(2);
	P7 = ccod_lsb;		//E=0,RS=0
	delay_micro(50);
}
//****************************************
//** ｷｬﾗｸﾀLCD　ﾃﾞｰﾀｺｰﾄﾞ出力
//
void lcd_dout(unsigned char dcod)
{
	unsigned char dcod_msb;
	unsigned char dcod_lsb;

	dcod_msb = dcod / 0x10;
	dcod_lsb = dcod & 0x0F;
//
	P7 = dcod_msb | 0x10;	//E=0,RS=1 + MSB
	delay_micro(2);
	P7 = dcod_msb | 0x30;	//E=1,RS=1
	delay_micro(2);
	P7 = dcod_msb | 0x10;	//E=0,RS=1
//
	delay_micro(2);
//
	P7 = dcod_lsb | 0x10;	//E=0,RS=1 + LSB
	delay_micro(2);
	P7 = dcod_lsb | 0x30;	//E=1,RS=1
	delay_micro(2);
	P7 = dcod_lsb | 0x10;	//E=0,RS=1
	delay_micro(50);
//
}
//*****************************************
//** ﾏｲｸﾛ秒遅延
void delay_micro(unsigned int icnt)
{
	unsigned int del_cnt,cnt2;

	for (del_cnt=0;del_cnt<icnt;del_cnt++){
		for (cnt2=0; cnt2<11; cnt2++){
			cnt2++;
		}
//			NOP();                      //to use NOP() funciton, it must be define in sfr.h header file
//			NOP();
//			NOP();
//			NOP();
//			NOP();
	}
}
//******************************************
//** ﾐﾘ秒遅延
void delay_msec(unsigned int icnt)
{
	unsigned int del_cnt;

	for (del_cnt=0;del_cnt<icnt;del_cnt++){
//		wdt_rst();
		delay_micro(1000);
	}
}
//******** END ********
