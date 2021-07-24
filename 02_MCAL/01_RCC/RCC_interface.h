#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

// Microcontroller clock output (MCO) options:
#define RCC_u8MCO_NO_CLK  0b000
#define RCC_u8MCO_SYS_CLK 0b100
#define RCC_u8MCO_HSI     0b101
#define RCC_u8MCO_HSE     0b110
#define RCC_u8MCO_PLL     0b111


ERROR_STATE_t RCC_u8ClockInit(void);
ERROR_STATE_t RCC_u8MCUClockOutput(u8 Copy_u8OutPutSource);
ERROR_STATE_t RCC_u8EnablePeripheralBus(STM32_u8Bus_t Copy_u8Bus, u8 Copy_u8Peripheral);
ERROR_STATE_t RCC_u8DisablePeripheralBus(STM32_u8Bus_t Copy_u8Bus, u8 Copy_u8Peripheral);


#endif