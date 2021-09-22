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
//*** function�i�֐��錾�j
//***
void 	main(void);
void		IO_Init(void);		//IO�߰ā@������
void 		settei_gen(void);	//�ݒ��ް��쐬
void 		swin_8d(void);		//�S�ި��߽�������
unsigned char 	swin_1d(unsigned char sw_no);	//�ި��߽��� 1������
//void 		led_con(void);		//LED����(Ҳ�)
//void 		monitor_ledcon(void);	//�ӺݒʐM�����\��Ӱ��LED����
//void 		error_ledcon(void);	//�װ�\��Ӱ��LED����


//**********************************************************************
//*** define�@(������`�j
//***            1234567890123456789
//#define VER	"SLP10-VT_SIO V1.00 " //�ő�26Byte�Ŏw��̂���

//**********************************************************************
//*** bariables�i�ϐ��錾�j
//***
//*  �ݒ轲��
unsigned char	mode_settei;		//���M����ؑ֐ݒ�	
unsigned char	frequency_settei;	//���M���g���`�����l��(7�`46CH)
unsigned char	length_settei;		//���蒌�S��
unsigned int	level_settei;		//���ٕ␳�l
unsigned char 	sw_id[8];		//�ݒ�X�C�b�`�@�Ǐo���f�[�^
//
unsigned char 	modef 	= 0;		//����X�C�b�`�@�t���O�iON���P�j
unsigned char 	upf 	= 0;
unsigned char 	downf 	= 0;
unsigned char 	leftf 	= 0;
unsigned char 	rightf 	= 0;
unsigned char 	setf 	= 0;
//*  LED
//unsigned char	sleep_flag;
//unsigned char	tx1_flag;		//���M���׸�
//unsigned char	rtx_flag;		//�Ӻݑ��M���׸�
//unsigned char	rrx_flag;		//�Ӻݎ�M���׸�
//unsigned char	sng_flag;		//�ݻ��ُ��׸�
//unsigned char	bng_flag;		//�d���ُ��׸�

/*  UART1(MU-3) & 2(�O���ر�)
unsigned char	ID[16];		//���͐��f�[�^
unsigned int	hbcd;		//����
unsigned int	hbc;
unsigned char	herr;
unsigned char	uart1_buf[32];	//�o�̓o�b�t�@�[
unsigned char	uart1_buf_cnt;	//�o�̓J�E���^�[
unsigned char	uart2_buf[32];	//�o�̓o�b�t�@�[
unsigned char	uart2_buf_cnt;	//�o�̓J�E���^�[

//���蒌���͐��ް�
unsigned int	s0i = 0;
unsigned int	s00i = 0;
unsigned int	s000i = 0;
unsigned int	s0000i = 0;

//�������␳�㑪�蒌�ް�
unsigned int	s0ih = 0;
unsigned int	s00ih = 0;
unsigned int	s000ih = 0;
unsigned int	s0000ih = 0;
//����BCD&BC�ް�
unsigned int suii_bcd;
unsigned int suii_bc;
unsigned char s_error;		//�װ�׸�
*/
unsigned char dpcnt[4];
//************************************************************************
//* Function Name: main
//* Description  : This function implements main function.�i���C���֐��j
//* Arguments    : None
//* Return Value : None
//*************************************************************************
void main(void)
{
    	IO_Init();			//IO������
    	lcd_init();
//	UART1_initial();
//	UART2_initial();
//

    	while (1U)
	{
//�ݒ轲�����́ALED����
		swin_8d();		//�ݒ����
		settei_gen();		//�ݒ��ް��쐬
		dispset_titl();
//		led_con();		//LED����
//�ݻ�����
//		sens_process();		//�ݻ�����
//���ʃf�[�^�v�Z�i���蒷�␳�A���x���␳�A���ρA�j
		
//UART1 �o�͐���iMU-3�رُo�́j
//		UART1_txbuf_set();	//tx1_trans_flag = 1�̎��A���M�ޯ̧�փf�[�^�i�[
//		UART1_trans_1d();	//���M�ޯ̧���ް����L��Atx1 ���Mڼ޽���̂Ƃ��A1byte�o��

//UART2 �o�͐���i�O���رُo�́j
//		UART2_txbuf_set();	//tx2_trans_flag = 1�̎��A���M�ޯ̧�փf�[�^�i�[
//		UART2_trans_1d();	//���M�ޯ̧���ް����L��Atx2 ���Mڼ޽���̂Ƃ��A1byte�o��
//�X���[�v����

//
//�����ޯ����ϰ����
	WDTE = 0xAC;			//WDT ���


	}    
}

	

/* End user code. Do not edit comment generated here */

//********************************************
//**	���̓f�[�^���]�@���@�ݒ�ϐ�
//**	mode_settei 	= ���M����ؑ֐ݒ�
//**	frequency_settei= ���M���g���`�����l��(7�`46CH)
//**	length_settei 	= ���蒌�S��
//**	level_settei	= ���ٕ␳�l
//**
void settei_gen(void)
{
	unsigned char cd1,cd2;

//mode_settei <-,-,-,-,�A/��,-,���/�װ,LEDon>

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
//**    �ݒ轲��(8��)����
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
//**	�ݒ轲��1����
//**    sw_no = �����ԍ�(0�`7)
//**	�Ԑ��@= �Ǐo�����f�[�^
//**
unsigned char swin_1d(unsigned char sw_no)
{
	unsigned char sw_id;

	sw_no = sw_no << 3;	//���V�t�g3
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
//**  LED����	
//**  LED1(�d������) 	    	= P6_0
//**  LED2(TX�ް����M��)   	= P6_1
//**  LED3(�Ӻݑ��M��,�ݻ�NG)	= P6_2
//**  LED4(�Ӻݎ�M��,�ޯ��NG)	= P6_3 
/*
void led_con(void)
{
	if (mode_settei & 0x01 != 0){
		if (sleep_flag == 1) P6 = P6 & 0xFE;	// �d������ON(LED1)
		else P6 = P6 | 0x01;
		if (tx1_flag == 1) P6 = P6 & 0xFD;	// �ް����M��(LED2)
		else P6 = P6 | 0x02;
//
		if (mode_settei & 0x02 != 0){
			monitor_ledcon();		// ����ݸޕ\��Ӱ��
		}	
		else{
			error_ledcon();			// �װ�\��Ӱ��
		}
	}
}
*/
//*********************************************
//  ����ݸ�Ӱ�ޕ\��
//  �ӺݒʐM��Ԃ�����ݸ�
/*
void monitor_ledcon(void)
{
	if (rtx_flag != 0) P6 = P6 & 0xFB;		// �Ӻ݂֑��M��(LED3)
	else P6 = P6 | 0x04;
	if (rrx_flag != 0) P6 = P6 & 0xF7;		// �Ӻ݂����M��(LED4)
	else P6 = P6 | 0x08;
}
*/
//**********************************************
//  �װӰ�ޕ\��
//  �ݻ�NG�A�ޯ�ذNG�\��
/*
void error_ledcon(void)
{
	if (sng_flag != 0) P6 = P6 & 0xFB;		// �ް��擾NG(LED3)
	else P6 = P6 | 0x04;
	if (bng_flag != 0) P6 = P6 & 0xF7;		// �ޯ�ذ�d��NG(LED4)
	else P6 = P6 | 0x08;
}
*/
//**********************************************