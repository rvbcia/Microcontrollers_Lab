#include "stm32f4xx.h"
/*
	Lab1-3
*/
void delay(int i){
	for( ; i>0; --i){
		SysTick->LOAD =1999999;
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
		SysTick->CTRL &= -SysTick_CTRL_ENABLE_Msk;
	}
}
int main(void){
	  //int i;
		//int j;
	
	  RCC -> AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		GPIOD -> MODER |= GPIO_MODER_MODER15_0;
		GPIOD -> ODR |= GPIO_ODR_ODR_15;
	
	SysTick->LOAD = 1999999;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk;
	while(1){
/*		
			for(i = 0; i<1000; i++){
				for(j = 0; j<1000; j++){
			}
		} 
*/
		
		  //delay(1);
		  //GPIOD -> ODR ^= GPIO_ODR_ODR_12;
	}
		return 0;
	

}


void SysTick_Handler(void){
	GPIOD-> ODR ^= GPIO_ODR_ODR_15;
} 
