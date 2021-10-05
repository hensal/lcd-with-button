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
* File Name    : digitalio.h
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

#ifndef _DEGITAL_H_
#define _DEGITAL_H_
/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/

/*******************************************************************************
Macro definitions
*******************************************************************************/
/*******************************************************************************
** DGOUT_PROC	
********************************************************************************/
#define DGOUT_PROC(Out,In,Active)												\
{																				\
		DGOUT_setValue(Out,In,Active);											\
}

/*******************************************************************************
** DGIN_INIT0	
********************************************************************************/
#define DGIN_INIT0(Active)														\
{																				\
		DGIN_Initialize(Active);												\
		DGIN_Counter();															\
}

/*******************************************************************************
** DGIN_INIT	
********************************************************************************/
#define DGIN_INIT																\
{																				\
		DGIN_Counter_Clear();													\
}

/*******************************************************************************
** DGIN_PROC	
********************************************************************************/
#define DGIN_PROC(Fout, Port, Active, Value, Trig)								\
{																				\
	{																			\
		UCHAR ucret;															\
		ucret = DGIN_getValue(Port, Value/10, (UCHAR)Trig);						\
		if (Active == 1) {														\
			Fout = ucret & 0x01;												\
		}																		\
		else {																	\
			Fout = ~ucret & 0x01;												\
		}																		\
																				\
		DGIN_Counter();															\
	}																			\
}

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
/*	Function Prototype	*/
void	DGOUT_setValue( UCHAR port, UCHAR In, UCHAR Active );

void	DGIN_Initialize( UCHAR Active );
void	DGIN_Counter_Clear( void );
UCHAR	DGIN_getValue( UCHAR Port, UCHAR Value, UCHAR Trig );
void	DGIN_Counter( void );

#endif		/* _DEGITAL_H_ */
