// Board : STM32F103C8T6
// CMSIS Standard coding Style

#include "stm32f10x.h"

void delay(volatile unsigned int time);

int main(void){
  RCC->APB2ENR |= 0x10;                // Enable RCC
  GPIOC->CRH &= 0xFF0FFFFF;            // Clear bits from Config. register
  GPIOC->CRH |= 0x00300000;            // Set Config. regisetr bits for OUTPUT MODE
  GPIOC->ODR |= 0x2000;                // Set the PIN as HIGH in the Output Data Register

  while(1){
    GPIOC->ODR |= 0x2000;              // LED ON
    delay(500000);
    GPIOC->ODR |= 0x0000;              // LED OFF
    delay(500000);
  }
}

// Delay Function
void delay(volatile unsigned int time)
{
    while (time--) {}                    // Simple delay loop
}
  
