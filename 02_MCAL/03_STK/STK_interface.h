#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

ERROR_STATE_t STK_Init(void);
ERROR_STATE_t STK_SetBusyWait(u32 Copy_u32NumOfTicks);
ERROR_STATE_t STK_SetIntervalSingle(u32 Copy_u32NumOfTicks, void (*Copy_pFunction)(void));
ERROR_STATE_t STK_SetIntervalPeriodic(u32 Copy_u32NumOfTicks, void (*Copy_pFunction)(void));
ERROR_STATE_t STK_GetElapsedTime(u32* Copy_pu32ElapsedTime);
ERROR_STATE_t STK_GetRemainingTime(u32* Copy_pu32RemainingTime);
void STK_voidStopTimer(void);

#endif