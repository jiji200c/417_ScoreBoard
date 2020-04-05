 #include "stm32f10x.h"
 #include "7seg.h"
 
void clockInit(void)
{
    uint32_t temp = 0x00;
    //If you hover over the RCC you can go to the definition and then
    //see it is a structure of all the RCC registers.  Then you can
    //simply assign a value.
    RCC->CFGR = 0x07050002;     // Output PLL/2 as MCO,
                                // PLLMUL X3, PREDIV1 is PLL input

    RCC->CR =  0x01010081;      // Turn on PLL, HSE, HSI

    while (temp != 0x02000000)  // Wait for the PLL to stabilize
    {
        temp = RCC->CR & 0x02000000; //Check to see if the PLL lock bit is set
    }
	}		
		void delay(uint32_t count)
{
    int i=0;
    for(i=0; i< count; ++i)
    {
    }
}
		
	


void portClockInit(void)
{
	 //Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
}

void portSetup(void)
{
	// Write a 0xB ( 1011b ) into the configuration and mode bits for PB9 (GPIO)
    GPIOB->CRH |= GPIO_CRH_MODE10 | GPIO_CRH_MODE11 | GPIO_CRH_MODE12 | GPIO_CRH_MODE13; 
    GPIOB->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_CNF11 | GPIO_CRH_CNF12 | GPIO_CRH_CNF13);
	
	
	  GPIOC->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_MODE8 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF8 ;
	
	
}
	
void left_segment(int time_delay, int i)
{
	
	if (i==0){
		GPIOC->BSRR = GPIO_BSRR_BR8 ;
		GPIOB->ODR |= 0X0000;
				delay(time_delay);
		if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
		
		++i;
		else return;
		}
	

	
    if (i==1){
			GPIOC->BSRR = GPIO_BSRR_BR9 ;
			//GPIOB->ODR &= 0XFFFF;
			GPIOB->ODR = 0X40;   // this make PB6 to be 1
				delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
			
		++i;
			
		}
		if (i==2){
			GPIOC->BSRR = GPIO_BSRR_BR8 ;
			//GPIOB->ODR &= 0XBF;      
			GPIOB->ODR = 0X80;    // this makes  PB7 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
			
		++i;
			
		}
		////////

    if (i==3){
			GPIOC->BSRR = GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0X7F;      
			GPIOB->ODR = 0XC0;    // this makes PB6 and PB7 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
			
		++i;

		}



    if (i==4){
			GPIOC->BSRR = GPIO_BSRR_BR8 ;
			//GPIOB->ODR &= 0X30;      
			GPIOB->ODR = 0X4000;    // this makes PB14 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
		++i;		
			
			
		}

 
		 if (i==5){
			GPIOC->BSRR = GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0XBFFF;      
			GPIOB->ODR = 0X4040;    // this makes PB6 and PB14 to be 1
			delay(time_delay);	
			 if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
		++i;
			 
		}

    if (i==6){
			GPIOC->BSRR |= GPIO_BSRR_BR8;
			//GPIOB->ODR &= 0XBFBF;      
			GPIOB->ODR = 0X4080;    // this makes PB7 and PB14 to be 1
			delay(time_delay);	
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
			
				++i;
		
		}


  if (i==7){
		  GPIOC->BSRR |= GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0XBF7F;      
			GPIOB->ODR = 0X40C0;    // this makes PB6, PB7 and PB14 to be 1
			delay(time_delay);
		if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
		
			
			++i;
		
		}
	
			if (i==8){
		  GPIOC->BSRR |= GPIO_BSRR_BR8;
			//GPIOB->ODR &= 0XBF3F;      
			GPIOB->ODR = 0X8000;    // this makes PB15 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
			++i;
			
		}
			
			if (i==9){
		  GPIOC->BSRR |= GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0X7FFF;      
			GPIOB->ODR = 0X8040;    // this makes PB15 and PB6 to be 1
			delay(time_delay);
		}
			
		
//	else {
//		GPIOC->BSRR |= GPIO_BSRR_BR8;
//		GPIOB->ODR &= 0X75BF;
//	GPIOB->ODR |= 0X0000;
//    int temp = -1; 
//    i=temp;	
//	GPIOC->BSRR |= GPIO_BSRR_BS9;
//}	
		


	}

void right_segment(int time_delay,int j)
{
	if (j==0){
		GPIOC->BSRR = GPIO_BSRR_BR8 ;
		GPIOB->ODR = 0X0000;
     delay(time_delay);	
		if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
		++j;
		
		}
	

	
    if (j==1){
			GPIOC->BSRR = GPIO_BSRR_BR9 ;
		//	GPIOB->ODR &= 0XFFFF;
			GPIOB->ODR = 0X400;   // this make PB10 to be 1
      delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
			++j;
			
		}
		if (j==2){
			GPIOC->BSRR = GPIO_BSRR_BR8 ;
			//GPIOB->ODR &= 0XBFF;      
			GPIOB->ODR = 0X800;    // this makes  PB11 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
			
		++j;
		
		}
		////////

    if (j==3){
			GPIOC->BSRR = GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0X7FF;      
			GPIOB->ODR = 0XC00;    // this makes PB10 and PB11 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
			
		++j;
			else if ((GPIOB->IDR & GPIO_IDR_IDR9) == 0)
				return;
		}



    if (j==4){
			GPIOC->BSRR = GPIO_BSRR_BR8 ;
			//GPIOB->ODR &= 0X300;      
			GPIOB->ODR = 0X1000;    // this makes PB12 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
			
			++j;		
			
		}

 
		 if (j==5){
			GPIOC->BSRR = GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0XEFFF;      
			GPIOB->ODR = 0X1400;    // this makes PB10 and PB12 to be 1
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
			
		++j;
			
		}

    if (j==6){
			GPIOC->BSRR |= GPIO_BSRR_BR8;
			//GPIOB->ODR &= 0XEBFF;      
			GPIOB->ODR = 0X1800;    // this makes PB11 and PB12 to be 1
			delay(time_delay);	
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
				
			++j;
			
		}


  if (j==7){
		  GPIOC->BSRR |= GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0XE7FF;      
			GPIOB->ODR = 0X1C00;    // this makes PB10, PB11 and PB12 to be 1
			delay(time_delay);
		if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)
			
			++j;

		}
	
			if (j==8){
		  GPIOC->BSRR |= GPIO_BSRR_BR8;
		//	GPIOB->ODR &= 0XE3FF;      
			GPIOB->ODR = 0X2000;    // this makes PB13 to be 1
			GPIOB->BSRR |= GPIO_BSRR_BR14;
			delay(time_delay);
			if ((GPIOB->IDR & GPIO_IDR_IDR8) == 0)	
			
			++j;
			
		}
			
			if (j==9){
		  GPIOC->BSRR |= GPIO_BSRR_BR9;
			//GPIOB->ODR &= 0XDFFF;      
			GPIOB->ODR = 0X2400;    // this makes PB10 and PB13 to be 1
			delay(time_delay);
		}
			
		
//	else {
//		GPIOC->BSRR |= GPIO_BSRR_BR8;
//		GPIOB->ODR &= 0XDBFF;
//		GPIOB->ODR |= 0X0000;
//    int temp = -1; 
//    i=temp;	
//	GPIOC->BSRR |= GPIO_BSRR_BS9;
//}	
	
}
		void middle_segment(int time_delay,int i){
		
	if (i==0){
		GPIOC->BSRR = GPIO_BSRR_BR8 ;
		GPIOA->ODR |= 0X0000;
     delay(time_delay);
		if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)
			++i;
		}
	

	
    if (i==1){
			GPIOC->BSRR = GPIO_BSRR_BR9 ;
			GPIOA->ODR &= 0XFFFF;
			GPIOA->ODR |= 0X8;   // this make PA3 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)
			++i;
		}
		if (i==2){
			GPIOC->BSRR = GPIO_BSRR_BR8 ;
			GPIOA->ODR &= 0X7;      
			GPIOA->ODR |= 0X10;    // this makes  PA4 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)
	    	++i;
		}
		
    if (i==3){
			GPIOC->BSRR = GPIO_BSRR_BR9;
			GPIOA->ODR &= 0XEF;      
			GPIOA->ODR |= 0X18;    // this makes PA3 and PA4 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)
		  ++i;
		}



    if (i==4){
			GPIOC->BSRR = GPIO_BSRR_BR8 ;
			GPIOA->ODR &= 0XE7;      
			GPIOA->ODR |= 0X100;    // this makes PA8 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)
	  	++i;		
		}

 
		 if (i==5){
			GPIOC->BSRR = GPIO_BSRR_BR9;
			GPIOA->ODR &= 0XEFF;      
			GPIOA->ODR |= 0X108;    // this makes PA8 and PA3 to be 1
			delay(time_delay);	
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0) 
		  ++i;
		}

    if (i==6){
			GPIOC->BSRR |= GPIO_BSRR_BR8;
			GPIOA->ODR &= 0XEF7;      
			GPIOA->ODR |= 0X110;    // this makes PA8 and PA4 to be 1
			delay(time_delay);	
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)
		  ++i;
		}


     if (i==7){
		  GPIOC->BSRR |= GPIO_BSRR_BR9;
      GPIOA->ODR &= 0XEEF;      
			GPIOA->ODR |= 0X118;    // this makes PA3, PA4 and PA8 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0) 
			++i;
		}
	
			if (i==8){
		  GPIOC->BSRR |= GPIO_BSRR_BR8;
			GPIOA->ODR &= 0XEE7;      
			GPIOA->ODR |= 0X8000;    // this makes PA15 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)	
			++i;
		}
			
			if (i==9){
		  GPIOC->BSRR |= GPIO_BSRR_BR9;
			GPIOA->ODR &= 0X7FFF;      
			GPIOA->ODR |= 0X8008;    // this makes PA15 and PA3 to be 1
			delay(time_delay);
			if ((GPIOC->IDR & GPIO_IDR_IDR12) == 0)	
			++i;
   	}
			
//		
//	else 
//		
//		GPIOC->BSRR |= GPIO_BSRR_BR8;
//	  GPIOA->ODR &= 0X7FF7;
//    GPIOA->ODR |= 0X0000;
//    int temp = -1; 
//    i=temp;	
//	  GPIOC->BSRR |= GPIO_BSRR_BS9;
}	
		
	




	
void portSetup_middle(void)
{
	  GPIOA->CRH |= GPIO_CRH_MODE8 | GPIO_CRH_MODE15 ;
    GPIOA->CRH &= ~GPIO_CRH_CNF8 & ~GPIO_CRH_CNF15 ;
	
	  GPIOA->CRL |= GPIO_CRL_MODE3 | GPIO_CRL_MODE4 ;
    GPIOA->CRL &= ~GPIO_CRL_CNF3 & ~GPIO_CRL_CNF4 ;
	
	  GPIOC->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_MODE8 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF8 ;
}

	
void reset(void)
{
		 GPIOA->ODR &= 0X7FF7;
    GPIOA->ODR |= 0X0000;
	
	GPIOB->ODR &= 0XDBFF;
		GPIOB->ODR |= 0X0000;
	
			GPIOB->ODR &= 0X75BF;
	GPIOB->ODR |= 0X0000;
	
	
}

void portClockInit_left(void)
{
	 //Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
}

void portSetup_left(void)
{
	// Write a 0xB ( 1011b ) into the configuration and mode bits for PB9 (GPIO)
   // GPIOB->CRH |= GPIO_CRL_MODE6 | GPIO_CRL_MODE7 | GPIO_CRH_MODE14 | GPIO_CRH_MODE15; 
    //GPIOB->CRH &= ~(GPIO_CRL_CNF6 | GPIO_CRL_CNF7 | GPIO_CRH_CNF14 | GPIO_CRH_CNF15);
	
	
	  GPIOB->CRH |= GPIO_CRH_MODE14 | GPIO_CRH_MODE15 ;
    GPIOB->CRH &= ~GPIO_CRH_CNF14 & ~GPIO_CRH_CNF15 ;
	
	  GPIOB->CRL |= GPIO_CRL_MODE6 | GPIO_CRL_MODE7 ;
    GPIOB->CRL &= ~GPIO_CRL_CNF6 & ~GPIO_CRL_CNF7 ;
	
	  GPIOC->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_MODE8 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF8 ;
}