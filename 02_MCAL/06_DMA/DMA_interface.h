#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef struct
{
    u8 ChannelNumber;
    DMA_ChMode_t ChannelMode;
    DMA_ChPriority_t ChannelPriority;
    DMA_DataSize_t ChannelSize;
    DMA_DataSize_t PeripheralSize;
    DMA_IncrementMode_t IncrementMode;
    DMA_CircularMode_t CircularMode;
    DMA_Interrupt_t InterruptMode;
}DMA_ConfigVars_t;

    ERROR_STATE_t DMA_u8ChannelInit(DMA_ConfigVars_t* Copy_pstrChConfigVars);

    ERROR_STATE_t DMA_u8ChannelTransfer(DMA_ConfigVars_t* Copy_pstrChConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u16 Copy_u16TransfersNumber);

    ERROR_STATE_t DMA_u8ChannelTransferBusy(DMA_ConfigVars_t* Copy_pstrChConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u16 Copy_u16TransfersNumber);

    ERROR_STATE_t DMA_u8SetInterruptCallBack(DMA_ConfigVars_t* Copy_pstrChConfigVars,void (*pf)(void));

#endif 