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
* File Name    : int.c
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#ifdef __CCRL__
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "int.h"
#include "pragma.h"
#pragma interrupt	MD_INTP0(vect=INTP0)
#pragma interrupt	MD_INTP1(vect=INTP1)
#pragma interrupt	MD_INTP2(vect=INTP2)
#pragma interrupt	MD_INTP3(vect=INTP3)
#pragma interrupt	MD_INTP4(vect=INTP4)
#pragma interrupt	MD_INTP5(vect=INTP5)

#if (defined DEVICE_R5F1057AANA) || (defined DEVICE_R5F1058AALA)
#pragma interrupt	MD_INTP6(vect=INTP6)
#endif /* defined DEVICE_R5F1057AANA || defined DEVICE_R5F1058AALA */

#pragma interrupt	MD_INTAD(vect=INTAD)
#pragma interrupt	MD_INTCMP0(vect=INTCMP0)
#pragma interrupt	MD_INTCMP1(vect=INTCMP1)
//#pragma interrupt	MD_INTDOC(vect=INTDOC)
#pragma interrupt	MD_INTIT(vect=INTIT)

#else
#error "undefined compiler"
#endif

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
USHORT usgADCR;

/*******************************************************************************
Private variables and functions
*******************************************************************************/


/*******************************************************************************
* Function Name: __interrupt MD_INTP0
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP0( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTP1
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP1( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTP2
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP2( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTP3
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP3( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTP4
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP4( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTP5
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP5( void )
#else
#error "undefined compiler"
#endif
{
}

#if (defined DEVICE_R5F1057AANA) || (defined DEVICE_R5F1058AALA)
/*******************************************************************************
* Function Name: __interrupt MD_INTP6
* Description  : Interrupt processing of external interrupt of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTP6( void )
#else
#error "undefined compiler"
#endif
{
}
#endif /* defined DEVICE_R5F1057AANA || defined DEVICE_R5F1058AALA */

/*******************************************************************************
* Function Name: __interrupt MD_INTAD
* Description  : Interrupt processing of AD converter of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTAD( void )
#else
#error "undefined compiler"
#endif
{
	usgADCR = ADCR;
}

/*******************************************************************************
* Function Name: __interrupt MD_INTCMP0
* Description  : Interrupt processing of comparator0 of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTCMP0( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTCMP1
* Description  : Interrupt processing of comparator1 of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTCMP1( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTDOC
* Description  : Interrupt processing of DOC of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTDOC( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: __interrupt MD_INTIT
* Description  : Interrupt processing of interval timer of signal detection
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTIT( void )
#else
#error "undefined compiler"
#endif
{
}

/*******************************************************************************
* Function Name: INT_Init
* Description  : This function initializes the external INT,
*                including enable or disable,priority setting
* Arguments    : none
* Return Value : none
********************************************************************************/
void INT_Init( void )
{
	MK0L = 0xFF;			/* All individual interrupt is prohibited	*/
	IF0L = 0x00;			/* Interrupt request flag all clearness		*/
	PR00L = 0xFF;			/* Priority level clearness					*/
	PR10L = 0xFF;			/* Priority level clearness					*/

	MK0H = 0xFF;			/* All individual interrupt is prohibited	*/
	IF0H = 0x00;			/* Interrupt request flag all clearness		*/
	PR00H = 0xFF;			/* Priority level clearness					*/
	PR10H = 0xFF;			/* Priority level clearness					*/

	MK1L = 0xFF;			/* All individual interrupt is prohibited	*/
	IF1L = 0x00;			/* Interrupt request flag all clearness		*/
	PR01L = 0xFF;			/* Priority level clearness					*/
	PR11L = 0xFF;			/* Priority level clearness					*/

	MK1H = 0xFF;			/* All individual interrupt is prohibited	*/
	IF1H = 0x00;			/* Interrupt request flag all clearness		*/
	PR01H = 0xFF;			/* Priority level clearness					*/
	PR11H = 0xFF;			/* Priority level clearness					*/

	MK2L = 0xFF;			/* All individual interrupt is prohibited	*/
	IF2L = 0x00;			/* Interrupt request flag all clearness		*/
	PR02L = 0xFF;			/* Priority level clearness					*/
	PR12L = 0xFF;			/* Priority level clearness					*/

	MK2H = 0xFF;			/* All individual interrupt is prohibited	*/
	IF2H = 0x00;			/* Interrupt request flag all clearness		*/
	PR02H = 0xFF;			/* Priority level clearness					*/
	PR12H = 0xFF;			/* Priority level clearness					*/

	EGP0 = 0x00;			/* External interrupt rising edge	*/
	EGN0 = 0x00;			/* External interrupt rising edge	*/
	EGP1 = 0x00;			/* External interrupt rising edge	*/
	EGN1 = 0x00;			/* External interrupt rising edge	*/
}
