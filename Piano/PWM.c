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


#define arr_init 7199// Frequency = 72000 000 000/((7199+1)*(0+1)), 10000 times per second
#define psc_init 0


void PWM_Init(void)
{

	TIM1->ARR=arr_init;			//Setting counter auto-reload value
	TIM1->PSC=psc_init;			//Predivider settings

	TIM1->CCMR1|=6<<4;  	//CH1 PWM1 mode
	TIM1->CCMR1|=1<<3; 		//CH1 preloading enablement
	TIM1->CCER|=1<<0;   	//OC1 Output Enablation
	TIM1->BDTR|=1<<15;   	//MOE Main Output Enablation

	TIM1->CR1=0x0080;   	//ARPE enable
	TIM1->CR1|=0x01;    	//Enabling timer 1


	TIM1->CCR1 =0;
}

void PWM_duty(u16 PWM_DUTY)
{
	float PWM_VAL;

	PWM_VAL=(arr_init*PWM_DUTY/10000.0);
	TIM1->CCR1 =PWM_VAL;
}
