#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

// Buses
#define RCC_u8AHB_Bus   0
#define RCC_u8APB1_BUS  1
#define RCC_u8APB2_BUS  2

// Microcontroller clock output (MCO) options:
#define RCC_u8MCO_NO_CLK  0b000
#define RCC_u8MCO_SYS_CLK 0b100
#define RCC_u8MCO_HSI     0b101
#define RCC_u8MCO_HSE     0b110
#define RCC_u8MCO_PLL     0b111

u8 RCC_u8ClockInit(void);
u8 RCC_u8MCUClockOutput(u8 Copy_u8OutPutSource);
u8 RCC_u8EnablePeripheralBus(u8 Copy_u8Bus, u8 Copy_u8Peripheral);
u8 RCC_u8DisablePeripheralBus(u8 Copy_u8Bus, u8 Copy_u8Peripheral);

#endif