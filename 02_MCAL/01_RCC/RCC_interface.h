#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

// #include<STD_TYPES.h>



#define HSI (u8)0b00
#define HSE (u8)0b01
#define PLL (u8)0b10

u8 RCC_u8SelectPLLSource(u8 Copy_PLLSource);
u8 RCC_u8SelectSystemClockSource(u8 Copy_u8ClockSource);
u8 RCC_u8EnablePeripheralBus(u8 Copy_u8BusName);

#endif