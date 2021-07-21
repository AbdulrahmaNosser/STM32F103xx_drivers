#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include <STD_TYPES.h>


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
}RCC_REGISTERS_t;

#define RCC ((RCC_REGISTERS_t*) 0x40021000)

// CR register bits
#define HSION   0
#define HSIRDY  1
#define HSEON   16
#define CSSON   19
#define PLLON   24

// CFGR register bits
#define SW      0
#define SWS     2
#define PLLSRC  16
#define MCO     24

// AHBENR register bits
#define SDIOEN  10

// System clock options:
#define HSI 0b00
#define HSE 0b01
#define PLL 0b10

// Clock security system options:
#define CSS_OFF 0
#define CSS_ON  1

// PLL source options:
#define PLL_HSI 0
#define PLL_HSE 1

#endif