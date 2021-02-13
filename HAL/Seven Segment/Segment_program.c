/*
 * Segment_program.c
 *
 *  Created on: Feb 12, 2021
 *      Author: body_
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "Segment_config.h"
#include "Segment_interface.h"

static u16 SegNumbers[]={ 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F ,0x6F };



void SEGMENT_Display (u8 Num)
{


	Num = ~((u8)SegNumbers[Num]);

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PINA, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PINA, (GET_BIT(Num,0)));

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PINB, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PINB, (GET_BIT(Num,1)));

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PINC, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PINC, (GET_BIT(Num,2)));

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PIND, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PIND, (GET_BIT(Num,3)));

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PINE, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PINE, (GET_BIT(Num,4)));

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PINF, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PINF, (GET_BIT(Num,5)));

	DIO_voidSetPinDirection(SEGMENT_PORT, SEGMENT_PING, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(SEGMENT_PORT, SEGMENT_PING, (GET_BIT(Num,6)));

}
