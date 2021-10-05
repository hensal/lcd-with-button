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
* File Name    : common.c
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
#ifdef __CCRL__
__saddr UCHAR	fTx0Done;	/* UART0 transmission completion flag(For standing up detection of trigger flag) */
__saddr UCHAR	fTx6Done;	/* UART6 transmission completion flag(For standing up detection of trigger flag) */
__saddr UCHAR	fTm10ms;	/* 10ms cycle flag */
__saddr UCHAR	fTrg50ms;	/* Trigger flag of 50ms cycle */
__saddr UCHAR	fTrg1s;		/* Trigger flag of   1s cycle */
__saddr UCHAR	fTrg10ms;	/* Trigger flag of 10ms cycle */

#else
#error "undefined compiler"
#endif

/*******************************************************************************
* Function Name: MOV1_
* Description  : MOV1_
* Arguments    : Fin
* Return Value : The value set to the Input argument is returned.
********************************************************************************/
UCHAR MOV1_( UCHAR Fin )
{
	return Fin;
}

/*******************************************************************************
* Function Name: NOT1_
* Description  : NOT1_
* Arguments    : Fin
* Return Value : The value set to the Input argument is returned.(0 or 1)
********************************************************************************/
UCHAR NOT1_( UCHAR Fin )
{
	return (Fin == HIGH) ?  LOW : HIGH;
}

/*******************************************************************************
* Function Name: WAIT
* Description  : WAIT
* Arguments    : count
* Return Value : none
********************************************************************************/
void WAIT( UCHAR count )
{
	USHORT	delay = (count * 100);
	register USHORT	i;

	for (i = 0; i < delay; i++)
		__nop();
	return;
}

/*******************************************************************************
* Function Name: BitMemGet
* Description  : BitMemGet
* Arguments    : memp
*                count
* Return Value : BitMem
********************************************************************************/
UCHAR BitMemGet( UCHAR* memp, UCHAR count )
{
	UCHAR	bit_num;
	UCHAR	elem_num;
	UCHAR	work;

	elem_num = count / 8;
	bit_num = count % 8;
	work = (UCHAR)(*(memp + elem_num));
	work >>= bit_num;
	work &= 0x01;
	return(work);
}

/*******************************************************************************
* Function Name: ByteMemGet
* Description  : ByteMemGet
* Arguments    : memp
*                count
* Return Value : ByteMem
********************************************************************************/
UCHAR ByteMemGet( UCHAR* memp, UCHAR count )
{
	UCHAR	work;

	work = (UCHAR)(*(memp + count));
	return(work);
}

/*******************************************************************************
* Function Name: BitMemSet
* Description  : BitMemSet
* Arguments    : memp
*                count
*                value
* Return Value : none
********************************************************************************/
void BitMemSet( UCHAR* memp, UCHAR count, UCHAR value )
{
	UCHAR	elem_num;
	UCHAR	mask;
	UCHAR	update;

	mask = (UCHAR)0x01 << (count & 0x07);
	update = value << (count & 0x07);
	elem_num = count / 8;

	*((UCHAR*)(memp + elem_num)) &= ~mask;
	*((UCHAR*)(memp + elem_num)) |= update;
}

/*******************************************************************************
* Function Name: ByteMemSet
* Description  : ByteMemSet
* Arguments    : memp
*                count
*                value
* Return Value : none
********************************************************************************/
void ByteMemSet( UCHAR* memp, UCHAR count, UCHAR value )
{
	UCHAR*	work;

	work = memp + count;
	*work = value;
}

/*******************************************************************************
* Function Name: Port_Set
* Description  : Port_Set
* Arguments    : Port
*                TermNum
*                value
* Return Value : none
********************************************************************************/
void Port_Set( UCHAR Port, UCHAR TermNum, UCHAR Val )
{
	volatile UCHAR *ucp_port;
	UCHAR	ucport;
	UCHAR	ucset = Val;

	ucp_port = &P0;
	ucp_port += Port;
	ucport = *ucp_port;
	ucset = 1;
	ucset <<= TermNum;
	if (Val == HIGH){
		ucport |= ucset;
	}else{
		ucport &= ~ucset;
	}
	*ucp_port = ucport;
}

/*******************************************************************************
* Function Name: Port_Get
* Description  : Port_Get
* Arguments    : Port
*                TermNum
* Return Value : The value set to the Port is returned.(0 or 1)
********************************************************************************/
UCHAR Port_Get( UCHAR Port, UCHAR TermNum )
{
	volatile UCHAR *ucp_port;
	UCHAR	ucport;
	UCHAR	ucret;

	ucp_port = &P0;
	ucp_port += Port;
	ucport = *ucp_port;
	ucret = (ucport >> TermNum) & 0x01;

	return(ucret);
}
