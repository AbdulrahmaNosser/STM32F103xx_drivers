#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


ERROR_STATE_t EXTI_u8SetInterruptMask(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t Copy_u8EXTIStatus);
ERROR_STATE_t EXTI_u8SetInterruptEdge(EXTI_ID_t Copy_u8EXTINumber, u8 Copy_u8EXTIEdge);
ERROR_STATE_t EXTI_u8ClearInterruptPending(EXTI_ID_t Copy_u8EXTIID);
ERROR_STATE_t EXTI_u8IsInterruptActive(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t* Copy_pu8EXTIStatus);
ERROR_STATE_t EXTI_u8SetInterruptCallback(EXTI_ID_t Copy_u8EXTIID, void (*Copy_pfCallback)(void));

#endif