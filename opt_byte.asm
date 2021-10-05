;*******************************************************************************
;* DISCLAIMER
;* This software is supplied by Renesas Electronics Corporation and is only
;* intended for use with Renesas products. No other uses are authorized. This
;* software is owned by Renesas Electronics Corporation and is protected under
;* all applicable laws, including copyright laws.
;* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
;* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
;* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
;* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
;* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
;* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
;* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
;* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
;* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
;* Renesas reserves the right, without notice, to make changes to this software
;* and to discontinue the availability of this software. By using this software,
;* you agree to the additional terms and conditions found by accessing the
;* following link:
;* http://www.renesas.com/disclaimer
;*
;* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
;*******************************************************************************

;*******************************************************************************
;* File Name    : opt_byte.asm
;* Version      : Applilet EZ PL for RL78
;* Device(s)    : R5F1056A,R5F1057A,R5F1058A
;* Tool-Chain   : CC-RL
;* Description  : This file implements main function.
;* Creation Date: 2016/09/14
;*******************************************************************************

.section	.option_byte,	opt_byte
.CSEG		OPT_BYTE
		.db	0b11101110
		.db	0b00001111
		.db	0b11100001
		.db	0b00000100

.CSEG		AT	0x010C0
		.db	0b11101110
		.db	0b00001111
		.db	0b11100001
		.db	0b00000100

