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

/********************** NVIC **********************/

typedef struct
{
    volatile u32 ISER[3];
    volatile u32 reserved_1[29];
    volatile u32 ICER[3];
    volatile u32 reserved_2[29];
    volatile u32 ISPR[3];
    volatile u32 reserved_3[29];
    volatile u32 ICPR[3];
    volatile u32 reserved_4[29];
    volatile u32 IABR[3];
    volatile u32 reserved_5[61];
    volatile u32 IPR[20];
}NVIC_REGISTERS_t;

#define NVIC ((NVIC_REGISTERS_t*) 0xE000E100)

typedef enum NVIC_INTERRUPTS_t
{
    ISER_WWDG,
    ISER_PVD,
    ISER_TAMPER,
    ISER_RTC,
    ISER_FLASH,
    ISER_RCC,
    ISER_EXTI0,
    ISER_EXTI1,
    ISER_EXTI2,
    ISER_EXTI3,
    ISER_EXTI4,
    ISER_DMA1_Channel1,
    ISER_DMA1_Channel2,
    ISER_DMA1_Channel3,
    ISER_DMA1_Channel4,
    ISER_DMA1_Channel5,
    ISER_DMA1_Channel6,
    ISER_ADC1_2,
    ISER_USB_HP_CAN_TX,
    ISER_USB_LP_CAN_RX0,
    ISER_CAN_RX1,
    ISER_CAN_SCE,
    ISER_EXTI9_5,
    ISER_TIM1_BRK,
    ISER_TIM1_UP,
    ISER_TIM1_TRG_COM,
    ISER_TIM1_CC,
    ISER_TIM2,
    ISER_TIM3,
    ISER_TIM4,
    ISER_I2C1_EV,
    ISER_I2C1_ER,
    ISER_I2C2_EV,
    ISER_I2C2_ER,
    ISER_SPI1,
    ISER_SPI2,
    ISER_USART1,
    ISER_USART2,
    ISER_USART3,
    ISER_EXTI15_10,
    ISER_RTCAlarm,
    ISER_USBWakeup,
    ISER_TIM8_BRK,
    ISER_TIM8_UP,
    ISER_TIM8_TRG_COM,
    ISER_TIM8_CC,
    ISER_ADC3,
    ISER_FSMC,
    ISER_SDIO,
    ISER_TIM5,
    ISER_SPI3,
    ISER_UART4,
    ISER_UART5,
    ISER_TIM6,
    ISER_TIM7,
    ISER_DMA2_Channel1,
    ISER_DMA2_Channel2,
    ISER_DMA2_Channel3,
    ISER_DMA2_Channel4_5
}NVIC_INTERRUPTS_t;

/********************** NVIC **********************/

/********************** SCB **********************/

typedef struct
{
    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR1;
    volatile u32 SHPR2;
    volatile u32 SHPR3;
    volatile u32 SHCRS;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 MMAR;
    volatile u32 BFAR;
}SCB_REGISTERS_t;

#define SCB ((SCB_REGISTERS_t*) 0xE000ED00)

typedef enum SCB_AIRCR_BITS_t
{
    AIRCR_VECTRESET,
    AIRCR_VECTCLRACTIVE,
    AIRCR_SYSRESETREQ,
    AIRCR_bit03_reserved,
    AIRCR_bit04_reserved,
    AIRCR_bit05_reserved,
    AIRCR_bit06_reserved,
    AIRCR_bit07_reserved,
    AIRCR_PRIGROUP_0,
    AIRCR_PRIGROUP_1,
    AIRCR_PRIGROUP_2,
    AIRCR_bit11_reserved,
    AIRCR_bit12_reserved,
    AIRCR_bit13_reserved,
    AIRCR_bit14_reserved,
    AIRCR_ENDIANESS,
    AIRCR_VECTKEYSTAT_00,
    AIRCR_VECTKEYSTAT_01,
    AIRCR_VECTKEYSTAT_02,
    AIRCR_VECTKEYSTAT_03,
    AIRCR_VECTKEYSTAT_04,
    AIRCR_VECTKEYSTAT_05,
    AIRCR_VECTKEYSTAT_06,
    AIRCR_VECTKEYSTAT_07,
    AIRCR_VECTKEYSTAT_08,
    AIRCR_VECTKEYSTAT_09,
    AIRCR_VECTKEYSTAT_10,
    AIRCR_VECTKEYSTAT_11,
    AIRCR_VECTKEYSTAT_12,
    AIRCR_VECTKEYSTAT_13,
    AIRCR_VECTKEYSTAT_14,
    AIRCR_VECTKEYSTAT_15
}SCB_AIRCR_BITS_t;

/********************** SCB **********************/

/********************** EXTI **********************/

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_REGISTERS_t;

#define EXTI ((EXTI_REGISTERS_t*)0x40010400)

typedef enum EXTI_ID_t
{
    EXTI_ID_GPIOx_00,
    EXTI_ID_GPIOx_01,
    EXTI_ID_GPIOx_02,
    EXTI_ID_GPIOx_03,
    EXTI_ID_GPIOx_04,
    EXTI_ID_GPIOx_05,
    EXTI_ID_GPIOx_06,
    EXTI_ID_GPIOx_07,
    EXTI_ID_GPIOx_08,
    EXTI_ID_GPIOx_09,
    EXTI_ID_GPIOx_10,
    EXTI_ID_GPIOx_11,
    EXTI_ID_GPIOx_12,
    EXTI_ID_GPIOx_13,
    EXTI_ID_GPIOx_14,
    EXTI_ID_GPIOx_15,
    EXTI_ID_PVD,
    EXTI_ID_RTC,
    EXTI_ID_USB,
    EXTI_ID_Ethernet
}EXTI_ID_t;

typedef enum EXTI_VECT_t
{
    EXTI_VECT_GPIOx_00,
    EXTI_VECT_GPIOx_01,
    EXTI_VECT_GPIOx_02,
    EXTI_VECT_GPIOx_03,
    EXTI_VECT_GPIOx_04,
    EXTI_VECT_GPIOx_05_09,
    EXTI_VECT_GPIOx_10_15,
    EXTI_VECT_PVD,
    EXTI_VECT_RTC,
    EXTI_VECT_USB,
    EXTI_VECT_Ethernet
}EXTI_VECT_t;

typedef enum EXTI_MASK_STATUS_t
{
    EXTI_MASKED,
    EXTI_NOT_MASKED
}EXTI_MASK_STATUS_t;

typedef enum EXTI_INTERRUPT_EDGE_t
{
    EXTI_EDGE_RISING,
    EXTI_EDGE_FALLING,
    EXTI_EDGE_RISING_FALLING
}EXTI_INTERRUPT_EDGE_t;

/********************** EXTI **********************/

#endif