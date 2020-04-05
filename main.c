


/******************************************************************************
 * Name:    lab1_lib.c
 * Description: STM32 peripherals initialization and functions
 * Version: V1.00
 * Author: Dave Duguid / Trevor Douglas
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *          V1.1 reformatted (kjn)
 *****************************************************************************/
 #include "stm32f10x.h"
#include "interrupt.h"
 #include "7seg.h" 
 #include <stdio.h>
 int flag = 0;
void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & EXTI_PR_PR8)
	{
		GPIOC->ODR = GPIO_ODR_ODR8;
		flag = 1;
		EXTI->PR |= EXTI_PR_PR8;
	}
	
	
	
}
int main (void){
	EXTInit();
clockInit();
portClockInit();
portSetup();
portSetup_left();
portSetup_middle();
		
	
	while(1){
		
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)	
			{left_segment(6000000, 0);}
if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)	
			{middle_segment(6000000, 0);}

			if (flag == 1)	
			{right_segment(6000000, 0);
				flag = 0;
			}
	






		
}


}