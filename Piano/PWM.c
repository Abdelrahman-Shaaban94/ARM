/*
 * PWM.c
 *
 *  Created on: Feb 13, 2021
 *      Author: body_
 */


#include "PWM.h"

#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"






void PWM_Init(void)
{

	/* Setting counter auto-reload value (top)
	 * Prescaler settings
	 */
	TIM1->ARR= AutoReload;
	TIM1->PSC= prescaler;


	/*   PWM1 mode */
	CLR_BIT(TIM1->CCMR1,OC1M0);
	SET_BIT(TIM1->CCMR1,OC1M1);
	SET_BIT(TIM1->CCMR1,OC1M2);

	/*  enable & update CCR1 after overflow  */
	SET_BIT(TIM1->CCMR1,OC1);

	/*  enable CH1  */
	SET_BIT(TIM1->CCER,CC1E);

    /* Main Output Enable OC Enable */
	SET_BIT(TIM1->BDTR,MOE);

	/* APRE Bit enable buffer to hold  updated CCR1 value  */
	SET_BIT(TIM1->CR1,7);


	/* Enabling timer 1  */
	SET_BIT(TIM1->CR1,CEN);


	/* initial value for duty cycle  */
	TIM1-> CCR1 = 0;
}

void PWM_duty(u16 PWM_DUTY)
{

	TIM1->CCR1 = PWM_DUTY ;
}
