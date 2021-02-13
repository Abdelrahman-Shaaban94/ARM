/*
 * PWM.h
 *
 *  Created on: Feb 13, 2021
 *      Author: body_
 */

#ifndef PWM_H_
#define PWM_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"



typedef struct
{
	volatile u32 	CR1;
	volatile u32	CR2;
	volatile u32 	SMCR;
	volatile u32	DIER;
	volatile u32 	SR;
	volatile u32	EGR;
	volatile u32	CCMR1;
	volatile u32	CCMR2;
	volatile u32	CCER;
	volatile u32	CNT;
	volatile u32	PSC;
	volatile u32	ARR;
	volatile u32	PCR;
	volatile u32	CCR1;
	volatile u32	CCR2;
	volatile u32	CCR3;
	volatile u32	CCR4;
	volatile u32	BDTR;

}TIM1;


#define 	TIM1 		((TIM1*)0x40012C00)


void PWM_Init(void);
void PWM_duty(u16 PWM_DUTY);





#endif /* PWM_H_ */
