/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "PWM.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_GPIOA_ID);
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_TIM1_ID);
	DIO_voidSetPinDirection(DIO_U8_PORTA, DIO_U8_PIN8, DIO_OUTPUT_50MHZ_AF_PP);


	PWM_Init();
    /* Loop forever */
	while(1)
	{
	PWM_duty(500);// Set PWM to 500, Range 1 -> 1000
	}
}
