//*************************************************************************
//***  �T�u�֐� STKW-183 tmcTEST�p
//*************************************************************************
#include <stdio.h>
#include <string.h>
#include "iodefine.h"
#include "lcd_con.h"
#include "sub.h"
//*************************************************************************
unsigned char		before_opsw_id;
//*************************************************************************
//**   IO�|�[�g������
//**
void IO_Init(void)
{
    /* Start user code. Do not edit comment generated here */
//     int i;
//GPIO_Port �ݒ�
	P0 = 0;			//Port�o�̓��W�X�^ �����ݒ�
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
//Port���[�h���W�X�^ �Z�b�g�i1:INPUT�A0:OUTPUT�j
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
	 			//PM13=MU�d��--I/O�Œ�
	PM14 = 0x7f;		//RTC_CE �̂�output
	PM15 = 0xf3;		//S80,S90 input
/* pull-up resistor 1�F�v���A�b�v */
	PU0 = 0x09;		//SDC Card Ditect & SI(��ŊO����R�ɕύX) Pull-up
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

/* port mode control register 0:�f�W�^�����o�� 1�F�A�i���O����*/
	PMC0 = 0x00;
	PMC1 = 0x00;
	PMC10 = 0x00;
	PMC12 = 0x01;		//�d���d������	
	PMC14 = 0x00;
//��۸��߰ā^�޼����߰Đؑ֐ݒ�
	ADPC = 0x01;		//P20-P27,P150-P156���޼���IO�ɐݒ�
	PMC0 = 0xF3;		//ANI16,ANI17�g�p���Ȃ�
	//PMC1�ύX�Ȃ�
	PMC10 = 0xfe;		//ANI20�g�p���Ȃ�
	PMC12 = 0xff;		//ANI19�g�p����
	PMC14 = 0x7f;		//ANI18�g�p���Ȃ�	
//UART �ݒ�
			
//	for(i = 0; i < 16; i++) {
//		uart2_buf[i] = 0;
//	}
}
//****************************************************************
//***  �e����X�C�b�`�@����m�F
//**
void op_switich_in(void)
{
	unsigned char	opsw_id;
	
	opsw_id = op_swin_1d();		//�X�C�b�`�f�[�^�Ǎ���
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
//***************************************************************
//***  ����X�C�b�`����
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