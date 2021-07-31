#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


u8 NVIC_u8EnableInterrupt(NVIC_INTERRUPTS_t Copy_u8InterruptId);
u8 NVIC_u8DisableInterrupt(NVIC_INTERRUPTS_t Copy_u8InterruptId);
u8 NVIC_u8SetInterruptPending(NVIC_INTERRUPTS_t Copy_u8InterruptId);
u8 NVIC_u8ClearInterruptPending(NVIC_INTERRUPTS_t Copy_u8InterruptId);
u8 NVIC_u8InterruptIsActive(NVIC_INTERRUPTS_t Copy_u8InterruptId, u8* Copy_pu8InterruptStatus);
u8 NVIC_u8SetGroupPriority(NVIC_INTERRUPTS_t Copy_u8InterruptId, u8 Copy_u8GroupPriority);


#endif