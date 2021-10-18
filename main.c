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
#include "button.h"
#include <stdint.h>

void IO_Init(void);	
void op_switich_in(void);		
void op_switich_mdoef(void);
void op_switich_modef(void);
void op_switich_upf(void);
void op_switich_downf(void);
int op_switich_leftf(void);
void op_switich_rightf(void);
void op_switich_setf(void);
void IntToStr(unsigned int intval);
void op_switich_setff(void);

unsigned char 	modef 	= 0;		
unsigned char 	upf 	= 0;
unsigned char 	downf 	= 0;
unsigned char 	leftf 	= 0;
unsigned char 	rightf 	= 0;
unsigned char 	setf 	= 0;

unsigned char dpcnt[4];

unsigned const char Line191[32] = "Hello, World";
extern unsigned char Line22[32] = "9567   ";
//************************************************************************
//* Function Name: main
//* Description  : This function implements main function.ÅiÉÅÉCÉìä÷êîÅj
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
	//dispset_titl();
	
	display1();
	
	/* Main Loop */
	main_loop();	
	
	IO_Init();			//IOèâä˙âª
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
		
		op_switich_in();
		
	        op_switich_mdoef();
		
		op_switich_upf();
		
		op_switich_downf();
		
		op_switich_leftf();
		
		op_switich_rightf();
		
		op_switich_setf();			
			

#if !defined PWM_USED
		/* Processing at 10ms cycle */
		if(TM_10ms()){
			
		}
#endif /* end of defined PWM_USED */
	     }
    }
 
/*void IntToStr(unsigned int intval) {
        TITL111[0] = (tempp/1000) + 48;
        TITL111[1] = (tempp/100)%10 + 48;
        TITL111[2] = (tempp/10)%10 + 48;
        TITL111[3] = (tempp/1)%10 + 48;
       
}
*/

