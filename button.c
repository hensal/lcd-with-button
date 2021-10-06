#include <stdio.h>
#include <string.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sfr.h"
#include "button.h"

unsigned char		before_opsw_id;
//*************************************************************************
//**   IOポート初期化
//**
extern unsigned char TITL12[32] = "save the money ";
extern unsigned char TITL13[32] = "enjoy the life   ";

void IO_Init(void)
{
 //
}
//****************************************************************
//***  各操作スイッチ　操作確認
//**
void setup() {
          //intialize the  button as input     
}

void op_switich_in(void)
{
	unsigned char	opsw_id;
	
	opsw_id = op_swin_1d();		//スイッチデータ読込み
//
	if (opsw_id == before_opsw_id){
		if ((opsw_id & 0x01) == 0) modef = 1;
			if ((opsw_id & 0x02) == 0) upf = 1;
		if ((opsw_id & 0x04) == 0) downf = 1;
		if ((opsw_id & 0x08) == 0) leftf = 1;
		if ((opsw_id & 0x10) == 0) rightf = 1;
		if ((opsw_id & 0x20) == 0) setf = 1;
	}	
//
	before_opsw_id = opsw_id;
		
}	


void op_switich_mdoef(void)
{
	
			//スイッチデータ読込み
//
	if (modef == 1){
		lcd_cout(0x01);
	}	
//
	
		
}	
//*
//***************************************************************
//***  操作スイッチ入力
//**
unsigned char op_swin_1d(void)
{
	unsigned char swid;
	
	P0 = P0 | 0x20;		//op_switch common on
	delay_micro(100);	//100microsec delay
	swid = P2 & 0x3F;
	P0 = P0 & 0xDF;		//op_switch common off
	
	return swid;
}	
void dispset_titl1(void){
	
	unsigned char k;
	     k=0;
	     while(k<32)
	{
		lcd_dout(TITL12[k]);
		k++;
		if(k==16) {		
		lcd_cout(0xC0);
		}
	}
}