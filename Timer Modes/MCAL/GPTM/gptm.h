/*
 * gptm.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef MCAL_GPTM_GPTM_H_
#define MCAL_GPTM_GPTM_H_

#include "Libraries/MyP_Types.h"
#include "Libraries/bitwise.h"
#include "Libraries/tm4c123gh6pm.h"


void GPTM_init_timer (Int32_t timer,Int32_t config);
void GPTM_set_mode (Int32_t timer, Int32_t mode, Int32_t CountDIR);
void GPTM_set_time (Int32_t Timer_Load ,Int32_t mSec_time);
void GPTM_I_enable(Int32_t timer, Int32_t type);

void GPTM_T0A_Handler(void);


enum {T0,T1,T2,T3,T4,T5};
enum {A,B,AB};
enum {B16=0b100,B32=0b000};
enum {ONESHOT=1,PERIODIC,CAPTURE};
enum {DOWN,UP};
enum {TATORIS,CAMRIS,CAERIS,RTCRIS,TAMRIS,TBTORIS=8,CBMRIS,CBERIS,TBMRIS};

#endif /* MCAL_GPTM_GPTM_H_ */
