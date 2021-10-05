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
* File Name    : common.h
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

#ifndef _COMMON_H_
#define _COMMON_H_
/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define LOW		0
#define HIGH	1

#define NON		0
#define RISING	1
#define FALLING	2
#define BOTH	3

#define UP		0
#define DOWN	1

#define	fOFF	0
#define	fON		1

/* CLOCK SRC */
#define CLOCK_SRC_HIGHSPEED		0
#define CLOCK_SRC_MIDDLESPEED	1
#define CLOCK_SRC_X1			2
#define CLOCK_SRC_EXTERNAL		3

#define FLASHMODE_HS			0
#define FLASHMODE_LS			1
#define FLASHMODE_LV			2

#define	PANEL_TYPE_COMPARE		1
#define	PANEL_TYPE_RANGE		2
#define	PANEL_TYPE_BIT			3

/* A/D Converter PROPERTY */
#define	ADM0_INIT_VAL				0b00000000
#define ADM1_INIT_VAL				0b00100000
#define	ADM2_INIT_VAL				0b00000000
#define AD_CONVERSION_CLOCK_64		0b00000000
#define AD_CONVERSION_CLOCK_32		0b00001000
#define AD_CONVERSION_CLOCK_16		0b00010000
#define AD_CONVERSION_CLOCK_8		0b00011000
#define AD_CONVERSION_CLOCK_6		0b00100000
#define AD_CONVERSION_CLOCK_5		0b00101000
#define AD_CONVERSION_CLOCK_4		0b00110000
#define AD_CONVERSION_CLOCK_2		0b00111000
#define AD_HARDWARE_ELC_TRIGGER		0b11000001
#define AD_HARDWARE_ITM_TRIGGER		0b11000011

/* Comparator PROPERTY */
#define CMP_MODE_NORMAL				0
#define CMP_MODE_WINDOW				1
#define IVREF0						0
#define IVREF1						1
#define BGRVREF						2
#define DA							3
#define IVREF0_1					4
#define COMP0_MODE_NORMAL			0b00000000
#define COMP0_MODE_WINDOW			0b00000010
#define COM0_IVCMP0_SELECTED		0b00000100
#define COM0_PGA_SELECTED			0b00001000
#define COM0_IVREF0_SELECTED		0b00000001
#define COM0_DACOUTPUT_SELECTED		0b00000010
#define COM0_COMPISEL_SELECTED		0b00000000
#define COM0_BGRVREF_SELECTED		0b00000100
#define COMP0_FILTER_NONE			0b00000000
#define COMP0_FILTER_FCLK			0b00000001
#define COMP0_FILTER_FCLK_8			0b00000010
#define COMP0_FILTER_FCLK_32		0b00000011
#define COMP0_ONE_EDGE_INTERRUPT	0b00000000
#define COMP0_BOTH_EDGES_INTERRUPT	0b00001000
#define COMP0_RISING_INTERRUPT		0b00000000
#define COMP0_FALLING_INTERRUPT		0b00000100
#define COMP1_MODE_NORMAL			0b00000000
#define COMP1_MODE_WINDOW			0b00100000
#define COMP1_FILTER_NONE			0b00000000
#define COMP1_FILTER_FCLK			0b00010000
#define COMP1_FILTER_FCLK_8			0b00100000
#define COMP1_FILTER_FCLK_32		0b00110000
#define COM1_IVREF0_SELECTED		0b00000000
#define COM1_BGRVREF_SELECTED		0b01000000
#define COMP1_ONE_EDGE_INTERRUPT	0b00000000
#define COMP1_BOTH_EDGES_INTERRUPT	0b10000000
#define COMP1_RISING_INTERRUPT		0b00000000
#define COMP1_FALLING_INTERRUPT		0b01000000

/* SERIAL PROPERTY */
#define MODE_SEND			1
#define MODE_RECV			2
#define MODE_SENDRECV		3

/* ELC PROPERTY */
#define ELC_EVENT_LINK_OFF			0b00000000
#define ELC_EVENT_LINK_ADC			0b00000001
#define ELC_EVENT_LINK_TAU00		0b00000010
#define ELC_EVENT_LINK_TAU01		0b00000011
#define ELC_DESTINATION_COUNT		18

/* DTC PROPERTY */
#define DTC_DATA_SIZE_8BITS			0b00000000
#define DTC_DATA_SIZE_16BITS		0b01000000
#define DTC_REPEAT_INT_DISABLE		0b00000000
#define DTC_REPEAT_INT_ENABLE		0b00100000
#define DTC_CHAIN_TRANSFER_DISABLE	0b00000000
#define DTC_CHAIN_TRANSFER_ENABLE	0b00010000
#define DTC_DEST_ADDR_FIXED			0b00000000
#define DTC_DEST_ADDR_INCREMENTED	0b00001000
#define DTC_SOURCE_ADDR_FIXED		0b00000000
#define DTC_SOURCE_ADDR_INCREMENTED	0b00000100
#define DTC_REPEAT_AREA_DEST		0b00000000
#define DTC_REPEAT_AREA_SOURCE		0b00000010
#define DTC_TRANSFER_MODE_NORMAL	0b00000000
#define DTC_TRANSFER_MODE_REPEAT	0b00000001
#define DTC_ADCR_ADDRESS			0xFF1E
#define DTC_DODIR_ADDRESS			0x0512
#define DTC_DODSR_ADDRESS			0x0514
#define DTC_DOCR_ADDRESS			0x0511
#define DTC_ADM2_ADDRESS			0x0010

/* DOC PROPERTY */
#define DOC_DOPCF_INTERRUPT_DISABLE	0b00000000
#define DOC_DOPCF_INTERRUPT_ENABLE	0b00010000
#define DOC_MODE_COMPARISON			0b00000000
#define DOC_MODE_ADDITION			0b00000001
#define DOC_MODE_SUBTRACTION		0b00000010

/* STANDBY PROPERTY */
#define STANDBY_MODE_STOP			0
#define STANDBY_MODE_HALT			1

#define FACTOR_INTP0				0
#define FACTOR_INTP1				1
#define FACTOR_INTP2				2
#define FACTOR_INTP3				3
#define FACTOR_INTP4				4
#define FACTOR_INTP5				5
#define FACTOR_INTP6				6

#define STANDBY_USE_CMP0			0
#define STANDBY_USE_CMP1			1

/* It accesses the sfr area. */
#define	EZPL_ACCESS_SRF_AREA		0xFFF00

/*******************************************************************************
Typedef definitions
*******************************************************************************/
typedef	long			LONG;
typedef	int				INT;
typedef	short			SHORT;
typedef	char			CHAR;
typedef	unsigned long	ULONG;
typedef	unsigned int	UINT;
typedef	unsigned short	USHORT;
typedef	unsigned char	UCHAR;
typedef struct
{
	UCHAR  dtccr;
	UCHAR  dtbls;
	UCHAR  dtcct;
	UCHAR  dtrld;
	USHORT dtsar;
	USHORT dtdar;
}ST_DTC_DATA;

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/
#ifdef __CCRL__
extern	__saddr	UCHAR	fTx0Done;
extern	__saddr	UCHAR	fTx6Done;
extern	__saddr	UCHAR	fTm10ms;
extern	__saddr	UCHAR	fTrg50ms;
extern	__saddr	UCHAR	fTrg1s;
extern	__saddr	UCHAR	fTrg10ms;

#else
#error "undefined compiler"
#endif

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
/*	Function Prototype	*/
UCHAR	MOV1_( UCHAR );
UCHAR	NOT1_( UCHAR );

void	WAIT( UCHAR );
UCHAR	BitMemGet( UCHAR* memp, UCHAR count );
UCHAR	ByteMemGet( UCHAR* memp, UCHAR count );
void	BitMemSet( UCHAR* memp, UCHAR count, UCHAR value );
void	ByteMemSet( UCHAR* memp, UCHAR count, UCHAR value );
void	Port_Set( UCHAR Port, UCHAR TermNum, UCHAR Val );
UCHAR	Port_Get( UCHAR Port, UCHAR TermNum );
UCHAR	PORT_in( UCHAR ucPort );
void	PORT_out( UCHAR ucPort, UCHAR ucOut );

#endif /* _COMMON_H_ */
