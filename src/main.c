#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "peripherals.h"

#define USART2_IRQn 38

RCC_t   * const RCC     = (RCC_t    *)  0x40023800;
GPIOx_t * const GPIOA   = (GPIOx_t  *)  0x40020000;
USART_t * const USART2  = (USART_t  *)  0x40004400;
NVIC_t  * const NVIC    = (NVIC_t   *)  0xE000E100;

void initialise_monitor_handles(void);


char UART_read(void);

int main(void){
    
    int a, b;
    char input[10], letter;

    initialise_monitor_handles();

    for(;;){

        printf("\n\n\r");
        printf("\n\r+--------------+");
        printf("\n\r|   Addition   |");
        printf("\n\r+--------------+");

        puts("\n\rType in the first number:\r");
        for(int i = 0; i < 10; i++) input[i++] = '\0';
        for(int i = 0; (letter = UART_read()) != '\r'; ) input[i++] = letter;
        sscanf(input, "%d", &a);

        puts("\n\rType in the second number:\r");
        for(int i = 0; i < 10; i++) input[i++] = '\0';
        for(int i = 0; (letter = UART_read()) != '\r'; ) input[i++] = letter;
        sscanf(input, "%d", &b);

        printf("\n\n\rResult: %d + %d = %d", a, b, a + b) ;

    }
}
