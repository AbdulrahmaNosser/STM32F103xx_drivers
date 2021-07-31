#include<STD_TYPES.h>
#include<BIT_MATH.h>

#include<stm32f103xx.h>
#include<NVIC_interface.h>

u8 NVIC_u8EnableInterrupt(NVIC_INTERRUPTS_t Copy_u8InterruptId)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_u8InterruptId < 32)
    {
        SET_BIT(NVIC->ISER[0], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8InterruptId >= 32)
    {
        Copy_u8InterruptId -= 32;
        SET_BIT(NVIC->ISER[1], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    return Local_u8ErrorState;
}


u8 NVIC_u8DisableInterrupt(NVIC_INTERRUPTS_t Copy_u8InterruptId)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_u8InterruptId < 32)
    {
        SET_BIT(NVIC->ICER[0], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8InterruptId >= 32)
    {
        Copy_u8InterruptId -= 32;
        SET_BIT(NVIC->ICER[1], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    return Local_u8ErrorState;
}

u8 NVIC_u8SetInterruptPending(NVIC_INTERRUPTS_t Copy_u8InterruptId)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_u8InterruptId < 32)
    {
        SET_BIT(NVIC->ISPR[0], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8InterruptId >= 32)
    {
        Copy_u8InterruptId -= 32;
        SET_BIT(NVIC->ISPR[1], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    return Local_u8ErrorState;
}

u8 NVIC_u8ClearInterruptPending(NVIC_INTERRUPTS_t Copy_u8InterruptId)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_u8InterruptId < 32)
    {
        SET_BIT(NVIC->ICPR[0], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8InterruptId >= 32)
    {
        Copy_u8InterruptId -= 32;
        SET_BIT(NVIC->ICPR[1], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    return Local_u8ErrorState;
}

u8 NVIC_u8InterruptIsActive(NVIC_INTERRUPTS_t Copy_u8InterruptId, u8* Copy_pu8InterruptStatus)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_u8InterruptId < 32)
    {
        *Copy_pu8InterruptStatus = GET_BIT(NVIC->IABR[0], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8InterruptId >= 32)
    {
        Copy_u8InterruptId -= 32;
        *Copy_pu8InterruptStatus = GET_BIT(NVIC->IABR[1], Copy_u8InterruptId);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    return Local_u8ErrorState;
}

u8 NVIC_u8SetGroupPriority(NVIC_INTERRUPTS_t Copy_u8InterruptId, u8 Copy_u8GroupPriority)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    u8 Local_u8RegisterNumebr   = Copy_u8InterruptId / 4;
    u8 Local_u8ByteNumber       = (8 * (Copy_u8InterruptId % 4)) + 4;

    SCB->AIRCR = 0x05FA0300;
    
    CLR_BITS(NVIC->IPR[Local_u8RegisterNumebr], Local_u8ByteNumber, 0b0000);
    SET_BITS(NVIC->IPR[Local_u8RegisterNumebr], Local_u8ByteNumber, Copy_u8GroupPriority);

    return Local_u8ErrorState;
}