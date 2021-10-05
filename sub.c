//*************************************************************************
//***  サブ関数 STKW-183 tmcTEST用
//*************************************************************************
#include <stdio.h>
#include <string.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sub.h"
#include "sfr.h"
//*************************************************************************
unsigned char		before_opsw_id;
//*************************************************************************
//**   IOポート初期化
//**
extern unsigned char TITL12[32] = "save the money";
extern unsigned char TITL13[32] = "enjoy the life";

void IO_Init(void)
{
 //
}

void op_switich_modef(void)
{
	unsigned char	opsw_id;
	
	opsw_id = op_swin_1d();		//スイッチデータ読込み

	if (opsw_id == before_opsw_id){
		if ((opsw_id & 0x01) == 0) modef = 1;
		if(modef==1) {
		                lcd_cout(0x01);
				delay_msec(50);
				lcd_cout(0x0f);	
	          	}
            	}	
	      before_opsw_id = opsw_id;
          }	

unsigned char op_swin_1d(void)
{
	unsigned char swid;
	
	P0 = P0 | 0x20;		 //op_switch common on
	delay_micro(100);	         //100microsec delay
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