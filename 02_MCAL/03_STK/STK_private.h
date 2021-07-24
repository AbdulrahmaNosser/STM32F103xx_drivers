#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

// STK clock source options:
#define STK_ConfigAHB 0
#define STK_ConfigAHBDiv8 1

// call back function pointer
static void (*STK_pFunction)(void) = NULL_p_t;

//
typedef enum STK_u8TimerIntervalMode
{
    STK_u8TimerSingle,
    STK_u8TimerPeriodic
}STK_TimerIntervalMode_t;

// timer interval mode global variable
static STK_TimerIntervalMode_t STK_u8TimerIntervalMode;

// function handler
ERROR_STATE_t STK_u8PrivateFunctionHandler(void);


#endif