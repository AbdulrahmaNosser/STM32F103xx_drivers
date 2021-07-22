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


enum CR_REGISTERS
{
    HSION,
    HSIRDY,
    HSITRIM = 3,
    HSICAL  = 8,
    HSEON   = 16,
    HSERDY,
    HSEBYP,
    CSSON,
    PLLON   = 24,
    PLLRDY,
    PLL2ON,
    PLL2RDY,
    PLL3ON,
    PLL3RDY
};

enum CFGR_REGISTERS
{
    SW,
    SWS         = 2,
    HPRE        = 4,
    PPRE1       = 8,
    PPRE2       = 11,
    ADCPRE      = 14,
    PLLSRC      = 16,
    PLLXTPRE,
    PLLMUL,
    OTGFSPRE    = 22,
    MCO         = 24
};

enum AHBENR_REGISTERS
{
    SDIOEN  = 10    
};

// System clock options:
#define HSI 0b00
#define HSE 0b01
#define PLL 0b10

enum CSS_OPTIONS
{
    CSS_OFF,
    CSS_ON
};

enum PLL_SOURCE_OPTIONS
{
    PLL_HSI,
    PLL_HSE
};


// RCC private functions:
u8 Private_u8SelectPLLSource(void);
u8 Private_u8SetClockSecuritySystem(void);
#endif