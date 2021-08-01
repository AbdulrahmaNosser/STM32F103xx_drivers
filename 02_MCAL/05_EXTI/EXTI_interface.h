#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


ERROR_STATE_t EXTI_u8SetInterruptMask(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t Copy_u8EXTIStatus);
ERROR_STATE_t EXTI_u8SetEventMask(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t Copy_u8EXTIStatus);
ERROR_STATE_t EXTI_u8SetInterruptEdge(EXTI_ID_t Copy_u8EXTIID, EXTI_INTERRUPT_EDGE_t Copy_u8EXTIEdge);
ERROR_STATE_t EXTI_u8SoftwareInterrupt(EXTI_ID_t Copy_u8EXTIID);
ERROR_STATE_t EXTI_u8ClearInterruptPending(EXTI_ID_t Copy_u8EXTIID);
ERROR_STATE_t EXTI_u8IsInterruptActive(EXTI_ID_t Copy_u8EXTIID, EXTI_MASK_STATUS_t* Copy_pu8EXTIStatus);
ERROR_STATE_t EXTI_u8SetInterruptCallback(EXTI_VECT_t Copy_u8EXTVect, void (*Copy_pfCallback)(void));

#endif