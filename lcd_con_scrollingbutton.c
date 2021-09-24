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
extern unsigned char TITL100[16] = "DISPLAYtest 2021";
extern unsigned char TITL111[16] = "    ｶｳﾝﾀｰ =     ";

extern unsigned char TITL0[32] = "'0804-0810:04*01";
extern unsigned char TITL1[32] = "H =+0123 R=034.5";

extern unsigned char TITL2[32] = "ﾋｶｸ ｾｯﾃｲ     *02";
extern unsigned char TITL3[32] = "+0000            ";

extern unsigned char TITL4[32] = "ｴﾗ- ﾁｪｯｸ     *03";
extern unsigned char TITL5[32] = ">ｱﾘ     ﾅｼ       ";

extern unsigned char TITL6[32] = "ﾎｽｳ ｼｮﾘ     *04";
extern unsigned char TITL7[32] = ">ﾏｲﾅｽ ﾎｽｳ";

extern unsigned char TITL8[32] = "ｳﾘｮｳｹｲ　　*05";
extern unsigned char TITL9[32] = "0.5 >1";

extern unsigned char TITL10[32] = "ｾｷｻﾝ ｾｯﾄ　*06";
extern unsigned char TITL11[32] = "000.0";

extern unsigned char TITL12[32] = "ﾄｹｲ ｺｳｾｲ　*07";
extern unsigned char TITL13[32] = "0804-0810:04 ";

extern unsigned char TITL14[32] = "ｶｰﾄﾞｷﾛｸ/ｶｲｼｭｳ*08";
extern unsigned char TITL15[32] = ">ｶｰﾄﾞ ｶｲｼｭｳ";

extern unsigned char TITL16[32] = "ｶﾝｿｸｼｮ NO.   *09";
extern unsigned char TITL17[32] = "000000";

extern unsigned char TITL18[32] = "ｷﾛｸｼﾞｶﾝ*10";
extern unsigned char TITL19[32] = "010M　";

extern unsigned char TITL20[32] = "ｷﾛｸｼﾞｶﾝ2 *11";
extern unsigned char TITL21[32] = "000M ";

extern unsigned char TITL22[32] = "ﾒﾓﾘ ｸﾘｱ　 *12";
extern unsigned char TITL23[32] = "YES=ｾｯﾄ            ";

extern unsigned char TITL24[32] = "ｶｰﾄﾞ ｦ ｺｳｶﾝ ｼﾏｽｶ? *13";
extern unsigned char TITL25[32] = "YES=ｾｯﾄ ";

extern unsigned char TITL26[32] = "ｶｰﾄﾞ ｦ ﾇｷﾏｽｶ ？ *14";
extern unsigned char TITL27[32] = "YES=ｾｯﾄ            ";

extern unsigned char TITL28[32] = "ｶｰﾄﾞ ｦ ﾇｷﾏｽｶ ？ *15";
extern unsigned char TITL29[32] = "WAIT >>   ";

extern unsigned char TITL30[32] = "ｶｰﾄﾞ ｦ  ｾｯﾄ  ｼﾏｽｶ? *16";
extern unsigned char TITL31[32] = "YES=ｾｯﾄ    ";

extern unsigned char TITL32[32] = "ｻﾞﾝﾘｮｳ ｶｸﾆﾝ　*17 ";
extern unsigned char TITL33[32] = "YES=ｾｯﾄ    ";

extern unsigned char TITL34[32] = "ｷﾛｸ ｶｸﾆﾝ　*18";
extern unsigned char TITL35[32] = "YES=ｾｯﾄ    ";

extern unsigned char TITL36[32] = "ｶｷｺﾐ ｴﾗ-　*19";
extern unsigned char TITL37[32] = "YES=ｾｯﾄ    ";

extern unsigned char TITL38[32] = "ｶｲｼｭｳ ﾎｳﾎｳ　*20";
extern unsigned char TITL39[32] = ">ｶｰﾄﾞ RS232  ";

extern unsigned char TITL40[32] = "ｶｲｼｭｳ ﾖｳﾘｮｳ　*21";
extern unsigned char TITL41[32] = ">ｽﾍﾞﾃ ｾﾞﾝｶｲｲｺｲ  ";

extern unsigned char TITL42[32] = "ｶｲｼｭｳ ｶｲｼ（PCｶｰﾄﾞ）　*21";
extern unsigned char TITL43[32] = "YES=ｾｯﾄ   ";

//*****************************************
void dispset_titl(void)
{	
	unsigned char n;
	unsigned char dsp_buf;
      	label: 
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL0[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL1[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL2[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL3[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL4[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL5[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL6[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL7[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}	
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL8[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL9[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}	

	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL10[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL11[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL12[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL13[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL14[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL15[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL16[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL17[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}	

	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL18[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL19[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL20[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL21[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL22[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL23[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}

	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL24[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL25[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL26[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL27[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL28[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL29[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}
	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL30[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL31[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}

	delay_msec(1000);
	lcd_cout(0x01);
	
	lcd_l1(0x00);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL30[n];		//line 1
		lcd_dout(dsp_buf);		//1data write		
	}
	
	lcd_l2(0x40);				
	for (n=0 ;n<16 ;n++) {
		dsp_buf = TITL31[n];		//line 2
		lcd_dout(dsp_buf);		//1data write			
	}

	goto label;
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
//**　LCD初期化(Initialize)
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
//			NOP();
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
