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


/*  TimerFreq = ClockFreq /	(AutoReload*prescaler) */
#define AutoReload 1000
#define prescaler 8


/*        TIM1_CCMR1     */
#define     OC1      3
#define     OC1M0    4
#define     OC1M1    5
#define     OC1M2    6

/*        TIM1_CCER     */
#define    CC1E      0


/*        TIM1_BDTR     */
#define    MOE      15



/*        TIM1_CR1     */
#define    CEN      0


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

}TIM1_Type;


#define 	TIM1 		((TIM1_Type*)0x40012C00)


void PWM_Init(void);
void PWM_duty(u16 PWM_DUTY);





#endif /* PWM_H_ */
