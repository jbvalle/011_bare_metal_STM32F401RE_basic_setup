/**
 *@file main.c
 *@brief Register Level Programming Simple Blink Project
 *@include main.c
 **/

#include <stdint.h>
#include "peripherals.h"

#define MODER 2
#define pin5 5

/**
 * @brief Struct Pointer for RCC Peripherals assigned with fixed address specified in reference manual
 **/
RCC_t   * const RCC     = (RCC_t    *)  0x40023800; 
/**
 * @brief Struct Pointer for GPIOA Peripherals assigned with fixed address specified in reference manual
 **/
GPIOx_t * const GPIOA   = (GPIOx_t  *)  0x40020000;

/**
 *@brief This is a simple delay function implementation, that waits for <time>ms.
 *
 *In this implementation the inner for loop, cycles for 1600 CLK Cycles which results in around 1ms delay, depending on the parameter <time>, the amount of ms delay can be adjusted.
 *
 *@param[in] time | number of ms the processor should wait
 **/
void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}

/**
 *@brief Main entry point for blinking project.
 *
 *GPIOA Peripherals are configured to OUTPUT, with LED connected to PA5 being toggled every 100ms
 **/
int main(void){

    //Enable Clock to GPIOA Peripheral
    RCC->RCC_AHB1ENR |= 1;
    
    // Reset MODER Bitfield of PA5
    GPIOA->GPIOx_MODER &= ~(3 << (pin5 * MODER));
    // Write Value 1 to MODER Bitfield PA5 to configure PA5 as OUTPUT
    GPIOA->GPIOx_MODER |=  (1 << (pin5 * MODER));
    
    for(;;){
        // Toggle PA5
        //GPIOA->GPIOx_ODR ^= (1 << pin5);
        // Wait for 100ms
        wait_ms(100);
    }
}
