/**/
/** Name    : **/
/** Date    : **/
/** Version : **/
/** SWC     : **/

// #include "STD_TYPES.h"

#ifndef STM32F103XX_H
#define STM32F103XX_H

/********************** Buses **********************/


typedef enum STM32_u8Buses
{
    STM32_u8AHB_Bus,
    STM32_u8APB1_BUS,
    STM32_u8APB2_BUS,
}STM32_u8Bus_t;

// Peripheral buses
#define GPIOA_u8Bus STM32_u8APB2_BUS
#define GPIOB_u8Bus STM32_u8APB2_BUS
#define GPIOC_u8Bus STM32_u8APB2_BUS
#define GPIOD_u8Bus STM32_u8APB2_BUS
#define GPIOE_u8Bus STM32_u8APB2_BUS
#define GPIOF_u8Bus STM32_u8APB2_BUS
#define GPIOG_u8Bus STM32_u8APB2_BUS

/********************** Buses **********************/

/********************** RCC **********************/


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


enum RCC_CR_BITS
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

enum RCC_CFGR_BITS
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

enum RCC_AHBENR_BITS
{
    SDIOEN  = 10    
};

enum RCC_APB2ENR_BITS
{
    AFIOEN,
    IOPAEN  = 2,
    IOPBEN,    
    IOPCEN,    
    IOPDEN,    
    IOPEEN,    
    IOPFEN,    
    IOPGEN,
    ADC1EN,    
    ADC2EN,    
    TIM1EN,    
    SPI1EN,    
    TIM8EN,    
    USART1EN,    
    ADC3EN,    
    TIM9EN = 19,    
    TIM10EN,    
    TIM11EN    
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

/********************** RCC **********************/


/********************** GPIO **********************/


typedef struct
{
    volatile u32 CRL;
    volatile u32 CRH;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 BRR;
    volatile u32 LCKR;

}GPIO_REGISTERS_t;

#define GPIOA ((GPIO_REGISTERS_t*) 0x40010800)
#define GPIOB ((GPIO_REGISTERS_t*) 0x40010C00)
#define GPIOC ((GPIO_REGISTERS_t*) 0x40011000)
#define GPIOD ((GPIO_REGISTERS_t*) 0x40011400)
#define GPIOE ((GPIO_REGISTERS_t*) 0x40011800)
#define GPIOF ((GPIO_REGISTERS_t*) 0x40011C00)
#define GPIOG ((GPIO_REGISTERS_t*) 0x40012000)

// GPIO pin modes
// Input
#define    GPIO_u8InAnalog   0b0000
#define    GPIO_u8InFloat    0b1100
#define    GPIO_u8InPullDown 0b1000
#define    GPIO_u8InPullUp   0b11000

// Output 2MHz
#define    GPIO_u8OutGnrPushPull2MHz    0b0010
#define    GPIO_u8OutGnrDrain2MHz       0b0110
#define    GPIO_u8OutAltPushPull2MHz    0b1010
#define    GPIO_u8OutAltDrain2MHz       0b1110

// Output 10MHz
#define    GPIO_u8OutGnrPushPull10MHz   0b0001
#define    GPIO_u8OutGnrDrain10MHz      0b0101
#define    GPIO_u8OutAltPushPull10MHz   0b1001
#define    GPIO_u8OutAltDrain10MHz      0b1101

// Output 50MHz
#define    GPIO_u8OutGnrPushPull50MHz   0b0011
#define    GPIO_u8OutGnrDrain50MHz      0b0111
#define    GPIO_u8OutAltPushPull50MHz   0b1011
#define    GPIO_u8OutAltDrain50MHz      0b1111


typedef enum
{
    GPIO_u8Pin0,
    GPIO_u8Pin1,
    GPIO_u8Pin2,
    GPIO_u8Pin3,
    GPIO_u8Pin4,
    GPIO_u8Pin5,
    GPIO_u8Pin6,
    GPIO_u8Pin7,
    GPIO_u8Pin8,
    GPIO_u8Pin9,
    GPIO_u8Pin10,
    GPIO_u8Pin11,
    GPIO_u8Pin12,
    GPIO_u8Pin13,
    GPIO_u8Pin14,
    GPIO_u8Pin15
}GPIO_u8PinNumber;


/********************** GPIO **********************/

/********************** STK **********************/


typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_REGISTERS_t;

#define STK ((STK_REGISTERS_t*) 0xE000E010)

typedef enum STK_enuCTRLBits
{
    ENABLE,
    TICKINT,
    CLKSOURCE,
    COUNTFLAG = 16
}STK_u8CTRLBits_t;

typedef enum STK_enuLOADBits
{
    RELOAD
}STK_u8LOADBits_t;

typedef enum STK_enuVALBits
{
    CURRENT
}STK_u8VALBits_t;

typedef enum STK_enuCALIBBits
{
    TENMS,
    SKEW = 30,
    NOREF
}STK_u8CALIBBits_t;

/********************** STK **********************/

#endif