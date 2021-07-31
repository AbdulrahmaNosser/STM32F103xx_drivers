#include<STD_TYPES.h>
#include<BIT_MATH.h>
#include<stm32f103xx.h>

#include<EXTI_interface.h>

ERROR_STATE_t EXTI_u8SetInterruptMask(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t Copy_u8EXTIStatus)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;
    
    if (Copy_u8EXTIStatus == EXTI_NOT_MASKED)
    {
        SET_BIT(EXTI->IMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8EXTIStatus == EXTI_MASKED)
    {
        CLR_BIT(EXTI->IMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8SetInterruptEdge(EXTI_ID_t Copy_u8EXTINumber, u8 Copy_u8EXTIEdge);
ERROR_STATE_t EXTI_u8ClearInterruptPending(EXTI_ID_t Copy_u8EXTIID);
ERROR_STATE_t EXTI_u8IsInterruptActive(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t* Copy_pu8EXTIStatus);
ERROR_STATE_t EXTI_u8SetInterruptCallback(EXTI_ID_t Copy_u8EXTIID, void (*Copy_pfCallback)(void));