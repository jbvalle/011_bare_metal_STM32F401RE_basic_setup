#include <stdint.h>
#include "peripherals.h"

#define MODER 2
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
#define pin8 8
#define pin8 8
#define pin9 9
#define pin10 10
#define pin11 11
#define pin12 12
#define pin13 13
#define pin14 14

RCC_t   * const RCC     = (RCC_t    *)  0x40023800;
GPIOx_t * const GPIOA   = (GPIOx_t  *)  0x40020000;
USART_t * const USART2  = (USART_t  *)  0x40004400;
NVIC_t  * const NVIC    = (NVIC_t   *)  0xE000E100;


void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}
int main(void){

    RCC->RCC_AHB1ENR |= 1;
    
    GPIOA->GPIOx_MODER &= ~(3 << (pin5 * MODER));
    GPIOA->GPIOx_MODER |=  (1 << (pin5 * MODER));
    
    for(;;){
        GPIOA->GPIOx_ODR ^= (1 << pin5);
        wait_ms(100);
    }
}
