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
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "system.h"
#include "timer.h"
#include "watchdogtimer.h"
#include "panel.h"
#include "lcd_con.h"

void 	main(void);
void IO_Init(void);		//IOﾎﾟｰﾄ　初期化
//*  設定ｽｲｯﾁ
unsigned char 	modef 	= 0;		//操作スイッチ　フラグ（ON＝１）
unsigned char 	upf 	= 0;
unsigned char 	downf 	= 0;
unsigned char 	leftf 	= 0;
unsigned char 	rightf 	= 0;
unsigned char 	setf 	= 0;

unsigned char dpcnt[4];
//************************************************************************
//* Function Name: main
//* Description  : This function implements main function.（メイン関数）
//* Arguments    : None
//* Return Value : None
//*************************************************************************
void main( void );
void main_loop( void );

void main(void) {
     /* Hardware Initiate */
        hdwinit();

	/* Panel Initiate */
	panel_init0();
	
	/*LCD Initiate */
	lcd_init();
	
	/*LCD TITLE set */
	dispset_titl();		
	
	/* Main Loop */
	main_loop();	
	
	IO_Init();			//IO初期化
    	lcd_init();
}

void main_loop(void)
    {    	
    	while (1)
	      {
		/* Panel proccessing */
		panel();

		/* Watchdog timer reset start */
		WDT_Reset();
		
		//**** count ****
		dispset_count();

#if !defined PWM_USED
		/* Processing at 10ms cycle */
		if(TM_10ms()){
			
		}
#endif /* end of defined PWM_USED */
	     }
    }
