//***********************************************************************/
/*                                                                     */
/*  FILE        : SLP10_VT_SIO_TEST                                    */
/*  DATE        : 2019/12/10                                           */
/*  DESCRIPTION : Main Program                                         */
/*  CPU TYPE    : R5F104MG(AFB) 80pin   ROM:128kB   RAM:16384B         */
/*                                                                     */
/*  NOTE:THIS IS A TEST EXAMPLE.                                       */
/*                                                                     */
/***********************************************************************/

//**********************************************************************
//*** includes
//***
#include <stdio.h>
#include <string.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sub.h"
//#include "vm_in.h"
//#include "uart1.h"
//#include "uart2.h"
//**********************************************************************
//*** function（関数宣言）
//***
void 	main(void);
void		IO_Init(void);		//IOﾎﾟｰﾄ　初期化
void 		settei_gen(void);	//設定ﾃﾞｰﾀ作成
void 		swin_8d(void);		//全ﾃﾞｨｯﾌﾟｽｲｯﾁ入力
unsigned char 	swin_1d(unsigned char sw_no);	//ﾃﾞｨｯﾌﾟｽｲｯﾁ 1桁入力
//void 		led_con(void);		//LED制御(ﾒｲﾝ)
//void 		monitor_ledcon(void);	//ﾘﾓｺﾝ通信ﾓﾆﾀｰ表示ﾓｰﾄﾞLED制御
//void 		error_ledcon(void);	//ｴﾗｰ表示ﾓｰﾄﾞLED制御


//**********************************************************************
//*** define　(文字定義）
//***            1234567890123456789
//#define VER	"SLP10-VT_SIO V1.00 " //最大26Byteで指定のこと

//**********************************************************************
//*** bariables（変数宣言）
//***
//*  設定ｽｲｯﾁ
unsigned char	mode_settei;		//送信動作切替設定	
unsigned char	frequency_settei;	//送信周波数チャンネル(7～46CH)
unsigned char	length_settei;		//測定柱全長
unsigned int	level_settei;		//ﾚﾍﾞﾙ補正値
unsigned char 	sw_id[8];		//設定スイッチ　読出しデータ
//
unsigned char 	modef 	= 0;		//操作スイッチ　フラグ（ON＝１）
unsigned char 	upf 	= 0;
unsigned char 	downf 	= 0;
unsigned char 	leftf 	= 0;
unsigned char 	rightf 	= 0;
unsigned char 	setf 	= 0;
//*  LED
//unsigned char	sleep_flag;
//unsigned char	tx1_flag;		//送信中ﾌﾗｸﾞ
//unsigned char	rtx_flag;		//ﾘﾓｺﾝ送信中ﾌﾗｸﾞ
//unsigned char	rrx_flag;		//ﾘﾓｺﾝ受信中ﾌﾗｸﾞ
//unsigned char	sng_flag;		//ｾﾝｻｰ異常ﾌﾗｸﾞ
//unsigned char	bng_flag;		//電源異常ﾌﾗｸﾞ

/*  UART1(MU-3) & 2(外部ｼﾘｱﾙ)
unsigned char	ID[16];		//入力生データ
unsigned int	hbcd;		//水位
unsigned int	hbc;
unsigned char	herr;
unsigned char	uart1_buf[32];	//出力バッファー
unsigned char	uart1_buf_cnt;	//出力カウンター
unsigned char	uart2_buf[32];	//出力バッファー
unsigned char	uart2_buf_cnt;	//出力カウンター

//測定柱入力生ﾃﾞｰﾀ
unsigned int	s0i = 0;
unsigned int	s00i = 0;
unsigned int	s000i = 0;
unsigned int	s0000i = 0;

//歯抜け補正後測定柱ﾃﾞｰﾀ
unsigned int	s0ih = 0;
unsigned int	s00ih = 0;
unsigned int	s000ih = 0;
unsigned int	s0000ih = 0;
//水位BCD&BCﾃﾞｰﾀ
unsigned int suii_bcd;
unsigned int suii_bc;
unsigned char s_error;		//ｴﾗｰﾌﾗｸﾞ
*/
unsigned char dpcnt[4];
//************************************************************************
//* Function Name: main
//* Description  : This function implements main function.（メイン関数）
//* Arguments    : None
//* Return Value : None
//*************************************************************************
void main(void)
{
    	IO_Init();			//IO初期化
    	lcd_init();
//	UART1_initial();
//	UART2_initial();
//

    	while (1U)
	{
//設定ｽｲｯﾁ入力、LED制御
		swin_8d();		//設定入力
		settei_gen();		//設定ﾃﾞｰﾀ作成
		dispset_titl();
//		led_con();		//LED制御
//ｾﾝｻｰ入力
//		sens_process();		//ｾﾝｻｰ入力
//水位データ計算（測定長補正、レベル補正、平均、）
		
//UART1 出力制御（MU-3ｼﾘｱﾙ出力）
//		UART1_txbuf_set();	//tx1_trans_flag = 1の時、送信ﾊﾞｯﾌｧへデータ格納
//		UART1_trans_1d();	//送信ﾊﾞｯﾌｧにﾃﾞｰﾀが有り、tx1 送信ﾚｼﾞｽﾀ空のとき、1byte出力

//UART2 出力制御（外部ｼﾘｱﾙ出力）
//		UART2_txbuf_set();	//tx2_trans_flag = 1の時、送信ﾊﾞｯﾌｧへデータ格納
//		UART2_trans_1d();	//送信ﾊﾞｯﾌｧにﾃﾞｰﾀが有り、tx2 送信ﾚｼﾞｽﾀ空のとき、1byte出力
//スリープ制御

//
//ｳｫｯﾁﾄﾞｯｸﾞﾀｲﾏｰ制御
	WDTE = 0xAC;			//WDT ｸﾘﾔ


	}    
}

	

/* End user code. Do not edit comment generated here */

//********************************************
//**	入力データ反転　→　設定変数
//**	mode_settei 	= 送信動作切替設定
//**	frequency_settei= 送信周波数チャンネル(7～46CH)
//**	length_settei 	= 測定柱全長
//**	level_settei	= ﾚﾍﾞﾙ補正値
//**
void settei_gen(void)
{
	unsigned char cd1,cd2;

//mode_settei <-,-,-,-,連/間,-,ﾓﾆﾀ/ｴﾗｰ,LEDon>

	mode_settei = ~sw_id[0];

//** frequency_settei <-,40,20,10,8,4,2,1ch>

	cd1 = ~sw_id[1];
	cd1 = cd1 & 0x0F;
	if (cd1 > 4) cd1 = 0;
	cd2 = ~sw_id[2];
	cd2 = cd2 & 0x0F;
	if (cd2 > 9) cd2 = 0;
	frequency_settei = cd1 * 0x10 + cd2;
	if (frequency_settei < 7 || 46 < frequency_settei){
		 frequency_settei = 7;
	}

//** length_settei <8,4,2,1m,80,40,20,10cm>

	cd1 = ~sw_id[3];
	cd1 = cd1 & 0x0F;
	cd1 = cd1 << 4;
	if ((cd1 & 0x80) != 0){
		length_settei = cd1 | 0x05;
	}

//** level_settei <-,40,20,10,8,4,2,1m,80,40,20,10,8,4,2,1cm>

	cd1 = ~sw_id[5];
	cd2 = ~sw_id[6];
	cd1 = cd1 & 0x0F;
	cd2 = cd2 & 0x0F;
	level_settei = cd1 * 0x1000 + cd2 * 0x100;
	if (sw_id[4] & 0x01 == 0){
		level_settei = level_settei + 0x50;
 	}
}

//*********************************************
//**    設定ｽｲｯﾁ(8個)入力
//**    P4_3,4,5 = SW_SEL1,2,4
//**	P14_0,1,2,3 = SW_IN0,1,2,3
//**
void swin_8d(void)
{
	sw_id[0] = swin_1d(0);
 	sw_id[1] = swin_1d(1);
	sw_id[2] = swin_1d(2);
	sw_id[3] = swin_1d(3);
	sw_id[4] = swin_1d(4);
	sw_id[5] = swin_1d(5);
	sw_id[6] = swin_1d(6);
	sw_id[7] = swin_1d(7);
}

//*********************************************
//**	設定ｽｲｯﾁ1個入力
//**    sw_no = ｽｲｯﾁ番号(0～7)
//**	返数　= 読出したデータ
//**
unsigned char swin_1d(unsigned char sw_no)
{
	unsigned char sw_id;

	sw_no = sw_no << 3;	//左シフト3
	P4 = P4 & 0x01;
	P4 = P4 | sw_no;
//
	delay_micro(10);
//
	sw_id = P14;
	sw_id = 0x0F;
//
	return(sw_id);	
}
//********************************************
//**  LED制御	
//**  LED1(電源ﾗﾝﾌﾟ) 	    	= P6_0
//**  LED2(TXﾃﾞｰﾀ送信中)   	= P6_1
//**  LED3(ﾘﾓｺﾝ送信中,ｾﾝｻｰNG)	= P6_2
//**  LED4(ﾘﾓｺﾝ受信中,ﾊﾞｯﾃﾘNG)	= P6_3 
/*
void led_con(void)
{
	if (mode_settei & 0x01 != 0){
		if (sleep_flag == 1) P6 = P6 & 0xFE;	// 電源ﾗﾝﾌﾟON(LED1)
		else P6 = P6 | 0x01;
		if (tx1_flag == 1) P6 = P6 & 0xFD;	// ﾃﾞｰﾀ送信中(LED2)
		else P6 = P6 | 0x02;
//
		if (mode_settei & 0x02 != 0){
			monitor_ledcon();		// ﾓﾆﾀﾘﾝｸﾞ表示ﾓｰﾄﾞ
		}	
		else{
			error_ledcon();			// ｴﾗｰ表示ﾓｰﾄﾞ
		}
	}
}
*/
//*********************************************
//  ﾓﾆﾀﾘﾝｸﾞﾓｰﾄﾞ表示
//  ﾘﾓｺﾝ通信状態のﾓﾆﾀﾘﾝｸﾞ
/*
void monitor_ledcon(void)
{
	if (rtx_flag != 0) P6 = P6 & 0xFB;		// ﾘﾓｺﾝへ送信中(LED3)
	else P6 = P6 | 0x04;
	if (rrx_flag != 0) P6 = P6 & 0xF7;		// ﾘﾓｺﾝから受信中(LED4)
	else P6 = P6 | 0x08;
}
*/
//**********************************************
//  ｴﾗｰﾓｰﾄﾞ表示
//  ｾﾝｻｰNG、ﾊﾞｯﾃﾘｰNG表示
/*
void error_ledcon(void)
{
	if (sng_flag != 0) P6 = P6 & 0xFB;		// ﾃﾞｰﾀ取得NG(LED3)
	else P6 = P6 | 0x04;
	if (bng_flag != 0) P6 = P6 & 0xF7;		// ﾊﾞｯﾃﾘｰ電圧NG(LED4)
	else P6 = P6 | 0x08;
}
*/
//**********************************************