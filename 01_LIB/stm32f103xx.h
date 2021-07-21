/**/
/** Name    : **/
/** Date    : **/
/** Version : **/
/** SWC     : **/

// #include "STD_TYPES.h"

#ifndef STM32F103XX_H
#define STM32F103XX_H

typedef struct
{
    volatile u32 CR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 APB2RSTR;
    volatile u32 APB1RSTR;
    volatile u32 AHBENR;
    volatile u32 APB2ENR;
    volatile u32 APB1ENR;
    volatile u32 BDCR;
    volatile u32 CSR;

} RCC_Registers_t;


#define RCC ((RCC_Registers_t*) 0x40021000)


#endif