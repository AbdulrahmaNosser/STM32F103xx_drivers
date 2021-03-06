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
        BIT_SET(EXTI->IMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8EXTIStatus == EXTI_MASKED)
    {
        BIT_CLR(EXTI->IMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8SetEventMask(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t Copy_u8EXTIStatus)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;
    
    if (Copy_u8EXTIStatus == EXTI_NOT_MASKED)
    {
        BIT_SET(EXTI->EMR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
    }
    else if (Copy_u8EXTIStatus == EXTI_MASKED)
    {
        BIT_CLR(EXTI->EMR, Copy_u8EXTIID);
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
        BIT_CLR(EXTI->FTSR, Copy_u8EXTIID);
        BIT_SET(EXTI->RTSR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
        break;
    case EXTI_EDGE_FALLING:
        BIT_CLR(EXTI->RTSR, Copy_u8EXTIID);
        BIT_SET(EXTI->FTSR, Copy_u8EXTIID);
        Local_u8ErrorState = STD_TYPES_OK;
        break;
    case EXTI_EDGE_RISING_FALLING:
        BIT_SET(EXTI->RTSR, Copy_u8EXTIID);
        BIT_SET(EXTI->RTSR, Copy_u8EXTIID);
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

    BIT_SET(EXTI->SWIER, Copy_u8EXTIID);

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8ClearInterruptPending(EXTI_ID_t Copy_u8EXTIID)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    BIT_SET(EXTI->PR, Copy_u8EXTIID);

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8IsInterruptActive(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t* Copy_pu8EXTIStatus)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    *Copy_pu8EXTIStatus = BIT_GET(EXTI->PR, Copy_u8EXTIID);

    return Local_u8ErrorState;
}

ERROR_STATE_t EXTI_u8SetInterruptCallback(EXTI_VECT_t Copy_u8EXTVect, void (*Copy_pfCallback)(void))
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;
    
    Global_pfArray[Copy_u8EXTVect] = Copy_pfCallback;

    return Local_u8ErrorState;
}



// EXTI IRQ handlers
void EXTI0_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_GPIOx_00);
    if(Global_pfArray[EXTI_VECT_GPIOx_00] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_00]();
    }
}
void EXTI1_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_GPIOx_01);
    if(Global_pfArray[EXTI_VECT_GPIOx_01] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_01]();
    }
}

void EXTI2_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_GPIOx_02);
    if(Global_pfArray[EXTI_VECT_GPIOx_02] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_02]();
    }
}

void EXTI3_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_GPIOx_03);
    if(Global_pfArray[EXTI_VECT_GPIOx_03] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_03]();
    }
}

void EXTI4_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_GPIOx_04);
    if(Global_pfArray[EXTI_VECT_GPIOx_04] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_04]();
    }
}
//////////////////////////////////// fix
void EXTI9_5_IRQHandler(void)
{
    BITS_SET(EXTI->PR, EXTI_ID_GPIOx_05, 0b11111);
    if(Global_pfArray[EXTI_VECT_GPIOx_05_09] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_05_09]();
    }
}
//////////////////////////////////// fix
void EXTI15_10_IRQHandler(void)
{
    BITS_SET(EXTI->PR, EXTI_ID_GPIOx_10, 0b111111);
    if(Global_pfArray[EXTI_VECT_GPIOx_10_15] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_GPIOx_10_15]();
    }
}

void PVD_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_PVD);
    if(Global_pfArray[EXTI_VECT_PVD] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_PVD]();
    }
}

void RTCAlarm_IRQHandler(void)
{
    BIT_SET(EXTI->PR, EXTI_ID_RTC);
    if(Global_pfArray[EXTI_VECT_RTC] != NULL_p_t)
    {
        Global_pfArray[EXTI_VECT_RTC]();
    }
}
