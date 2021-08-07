#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef struct
{
    u8 ChannelNumber;
    DMA_ChMode_t ChannelMode;
    DMA_ChPriority_t ChannelPriority;
    DMA_ChSize_t ChannelSize;
    DMA_PeripheralSize_t PeripheralSize;
    DMA_IncrementMode_t IncrementMode;
    DMA_CircularMode_t CircularMode;
    DMA_Interrupt_t InterruptMode;
}DMA_ConfigVars_t;

    ERROR_STATE_t DMA_u8ChannelInit(DMA_ConfigVars_t* Copy_pstrChannelConfigVars);

    ERROR_STATE_t DMA_u8ChannelTransfer(DMA_ConfigVars_t* Copy_pstrChannelConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u32 Copy_u32TransfersNumber);

    ERROR_STATE_t DMA_u8ChannelTransferBusy(DMA_ConfigVars_t* Copy_pstrChannelConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u32 Copy_u32TransfersNumber);

    ERROR_STATE_t DMA_u8ChannelTransferBusy(DMA_ConfigVars_t* Copy_pstrChannelConfigVars,void (*pf)(void));

#endif 