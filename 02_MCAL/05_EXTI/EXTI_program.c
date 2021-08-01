#include<STD_TYPES.h>
#include<BIT_MATH.h>
#include<stm32f103xx.h>

#include<EXTI_interface.h>

//function pointer for interrput function call back
typedef void (*fptr)(void);
//array of function pointers for interrupts
static fptr Global_pfArray[9] = {NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, };

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

ERROR_STATE_t EXTI_u8SetEventMask(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t Copy_u8EXTIStatus)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;
    
    if (Copy_u8EXTIStatus == EXTI_NOT_MASKED)
    {
        SET_BIT(EXTI->EMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8EXTIStatus == EXTI_MASKED)
    {
        CLR_BIT(EXTI->EMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8SetInterruptEdge(EXTI_ID_t Copy_u8EXTIID, EXTI_INTERRUPT_EDGE_t Copy_u8EXTIEdge)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    switch (Copy_u8EXTIEdge)
    {
    case EXTI_EDGE_RISING:
        CLR_BIT(EXTI->FTSR, Copy_u8EXTIID);
        SET_BIT(EXTI->RTSR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
        break;
    case EXTI_EDGE_FALLING:
        CLR_BIT(EXTI->RTSR, Copy_u8EXTIID);
        SET_BIT(EXTI->FTSR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
        break;
    case EXTI_EDGE_RISING_FALLING:
        SET_BIT(EXTI->RTSR, Copy_u8EXTIID);
        SET_BIT(EXTI->RTSR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
        break;
    default:
        break;
    }
    
    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8SoftwareInterrupt(EXTI_ID_t Copy_u8EXTIID)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    SET_BIT(EXTI->SWIER, Copy_u8EXTIID);

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8ClearInterruptPending(EXTI_ID_t Copy_u8EXTIID)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    SET_BIT(EXTI->PR, Copy_u8EXTIID);

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8IsInterruptActive(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t* Copy_pu8EXTIStatus)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    *Copy_pu8EXTIStatus = GET_BIT(EXTI->PR, Copy_u8EXTIID);

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8SetInterruptCallback(EXTI_VECT_t Copy_u8EXTVect, void (*Copy_pfCallback)(void));
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;
    
    Global_pfArray[Copy_u8EXTVect] = Copy_pfCallback;

    return Local_u8ErrorState;
}