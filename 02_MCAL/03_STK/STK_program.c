#include<STD_TYPES.h>
#include<BIT_MATH.h>

#include<stm32f103xx.h>

#include<STK_interface.h>
#include<STK_private.h>
#include<STK_config.h>


ERROR_STATE_t STK_Init(void)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;
    
    // disable timer
    CLR_BIT(STK->CTRL, ENABLE);
    
    // select timer clock source
    #if (STK_u8ClockSource == STK_ConfigAHB)
        SET_BIT(STK->CTRL, CLKSOURCE);
    #elif (STK_u8ClockSource == STK_ConfigAHBDiv8)
        CLR_BIT(STK->CTRL, CLKSOURCE);
    #else
        #error "Invalid STK clock source"
    #endif

    return Local_u8ErrorState;
}

ERROR_STATE_t STK_SetBusyWait(u32 Copy_u32NumOfTicks)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_u32NumOfTicks <= 0x00FFFFFF)
    {
        Local_u8ErrorState = STD_TYPES_OK;
        // set the number of ticks
        SET_BITS(STK->LOAD, RELOAD, Copy_u32NumOfTicks);
        // start timer
        SET_BIT(STK->CTRL, ENABLE);
    }

    // wait for timer
    while (! GET_BIT(STK->CTRL, COUNTFLAG))
    {}
    // disable timer
    CLR_BIT(STK->CTRL, ENABLE);
    
    return Local_u8ErrorState;
}

ERROR_STATE_t STK_SetIntervalSingle(u32 Copy_u32NumOfTicks, void (*Copy_pFunction)(void))
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if ((Copy_u32NumOfTicks <= 0x00FFFFFF) && (Copy_pFunction != NULL_p_t))
    {
        Local_u8ErrorState = STD_TYPES_OK;
        // set the number of ticks and enable
        SET_BITS(STK->LOAD, RELOAD, Copy_u32NumOfTicks);
        SET_BIT(STK->CTRL, ENABLE);

        // set call back function
        STK_pFunction = Copy_pFunction;
        // enable interrupt
        SET_BIT(STK->CTRL, TICKINT);
        // set timer interval mode
        STK_u8TimerIntervalMode == STK_u8TimerSingle;
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t STK_SetIntervalPeriodic(u32 Copy_u32NumOfTicks, void (*Copy_pFunction)(void))
{
        ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if ((Copy_u32NumOfTicks <= 0x00FFFFFF) && (Copy_pFunction != NULL_p_t))
    {
        Local_u8ErrorState = STD_TYPES_OK;
        // set the number of ticks and enable
        SET_BITS(STK->LOAD, RELOAD, (Copy_u32NumOfTicks - 1) );
        SET_BIT(STK->CTRL, ENABLE);

        // set call back function
        STK_pFunction = Copy_pFunction;
        // enable interrupt
        SET_BIT(STK->CTRL, TICKINT);
        // set timer interval mode
        STK_u8TimerIntervalMode == STK_u8TimerPeriodic;
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t STK_GetElapsedTime(u32* Copy_pu32ElapsedTime)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_pu32ElapsedTime != NULL_p_t)
    {
        Local_u8ErrorState = STD_TYPES_OK;

        *Copy_pu32ElapsedTime = GET_BITS(STK->LOAD, RELOAD, 0xFFFFFF)  - GET_BITS(STK->VAL, CURRENT, 0xFFFFFF);
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t STK_GetRemainingTime(u32* Copy_pu32RemainingTime)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (Copy_pu32RemainingTime != NULL_p_t)
    {
        Local_u8ErrorState = STD_TYPES_OK;

        // reads the current and the loaded values of the timer and subtracts them to get the remaining time 
        *Copy_pu32RemainingTime = GET_BITS(STK->LOAD, RELOAD, 0xFFFFFF);
    }

    return Local_u8ErrorState;
}

void STK_voidStopTimer(void)
{
    CLR_BIT(STK->CTRL, ENABLE);
}

ERROR_STATE_t STK_u8PrivateFunctionHandler(void)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_NOK;

    if (STK_pFunction != NULL_p_t)
    {
        // call function
        STK_pFunction();
        Local_u8ErrorState = STD_TYPES_OK;
    }
    
    // if single shit timer 
    if (STK_u8TimerIntervalMode == STK_u8TimerSingle)
    {
        // disable interrupt
        CLR_BIT(STK->CTRL, TICKINT);
        // disable timer
        CLR_BIT(STK->CTRL, ENABLE);
    }
    
    // read to clear the counter flag
    GET_BIT(STK->CTRL, COUNTFLAG);
    
    return Local_u8ErrorState;
}
