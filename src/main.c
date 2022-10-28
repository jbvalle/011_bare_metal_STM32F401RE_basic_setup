/**
 *@file main.c
 *@brief Register Level Programming Simple Blink Project
 **/

#include <stdint.h>
#include "peripherals.h"

#define MODER 2
#define pin5 5

RCC_t   * const RCC     = (RCC_t    *)  0x40023800;
GPIOx_t * const GPIOA   = (GPIOx_t  *)  0x40020000;

/**
 *@brief Function is a simple sleep function implementation, that waits for <time>ms
 *In this implementation the inner for loop, cycles for 1600 CLK Cycles which results in around 1ms delay, depending on the parameter <time>, the amount of ms delay can be adjusted.
 *@param[in] time | number of ms the processor should wait
 **/
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
