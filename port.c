/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name    : port.c
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "port.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/

/*******************************************************************************
Private variables and functions
*******************************************************************************/

/*******************************************************************************
* Function Name: PORT_Init
* Description  : This function initializes the I/O port module.
* Arguments    : none
* Return Value : none
********************************************************************************/
void PORT_Init( void )
{
	   /* Start user code. Do not edit comment generated here */
//     int i;
//GPIO_Port 設定
	P0 = 0;			//Port出力レジスタ 初期設定
	P1 = 0;
	P2 = 0;
	P3 = 0x01;		//LCD POWER ON
	P4 = 0;
	P5 = 0;
	P6 = 0;
	P7 = 0;	
	P10 = 0x01;		//FRAM DISABLE
	P11 = 0;
	P13 = 0;
	P14 = 0;	
	P15 = 0;
//Portモードレジスタ セット（1:INPUT、0:OUTPUT）
	PM0  = 0x09;		//N,SW_COM,(CLK,DO,CS,Dtect)SDCard
	PM1  = 0x32;		//AUX_UART & RTC IF
	PM2  = 0xff;		//S00~S70 input Port
	PM3  = 0xfe;		//LCD POWER output IF
	PM4  = 0xc7;		//SW_SEL output Port
	PM5  = 0xff;		//S400~S1000 input Port
	PM6  = 0xf0;		//S000~S300 input/LED1~4 output
	PM7  = 0x00;		//S0~S7 output
	PM10 = 0xfe;		//FRAM_CS output
	PM11 = 0xff;		//NC intput(inner pull up)
	PM12 = 0xff;		//input(X,XT)
	 			//PM13=MU電源--I/O固定
	PM14 = 0x7f;		//RTC_CE のみoutput
	PM15 = 0xf3;		//S80,S90 input
/* pull-up resistor 1：プルアップ */
	PU0 = 0x09;		//SDC Card Ditect & SI(後で外部抵抗に変更) Pull-up
	PU1 = 0x00;
	PU3 = 0x02;
	PU4 = 0x06;
	PU5 = 0x00;
	PU6 = 0x00;
	PU7 = 0x00;
	PU10 = 0x00;
	PU11 = 0x03;
	PU12 = 0x00;
	PU14 = 0x10;		//SDC Write Protect Pull-up

/* port mode control register 0:デジタル入出力 1：アナログ入力*/
	PMC0 = 0x00;
	PMC1 = 0x00;
	PMC10 = 0x00;
	PMC12 = 0x01;		//電源電圧入力	
	PMC14 = 0x00;
//ｱﾅﾛｸﾞﾎﾟｰﾄ／ﾃﾞｼﾞﾀﾙﾎﾟｰﾄ切替設定
	ADPC = 0x01;		//P20-P27,P150-P156をﾃﾞｼﾞﾀﾙIOに設定
	PMC0 = 0xF3;		//ANI16,ANI17使用しない
	//PMC1変更なし
	PMC10 = 0xfe;		//ANI20使用しない
	PMC12 = 0xff;		//ANI19使用する
	PMC14 = 0x7f;
}
