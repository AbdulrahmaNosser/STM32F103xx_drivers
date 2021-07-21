#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// #include <STD_TYPES.h>

#define RCC_u32_BASE_ADDRESS    0x40021000
#define RCC_u32_CR              *((volatile u32*) RCC_u32_BASE_ADDRESS)
#define RCC_u32_CFGR            *((volatile u32*) RCC_u32_BASE_ADDRESS + 0x04)

#endif