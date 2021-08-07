#include<STD_TYPES.h>
#include<BIT_MATH.h>
#include<stm32f103xx.h>
#include<DMA_interface.h>


ERROR_STATE_t DMA_u8ChannelInit(DMA_ConfigVars_t* Copy_pstrChConfigVars)
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    if (Copy_pstrChConfigVars != NULL_p_t)
    {
        Local_ErrorState = STD_TYPES_OK;
        u8 ChNum = Copy_pstrChConfigVars->ChannelNumber - 1;

        // clear register bits
        BITS_CLR(DMA->Channel[ChNum].CCR, DIR, 0x00 );

        // channel transfer mode
        BITS_SET(DMA->Channel[ChNum].CCR, MEM2MEM, (Copy_pstrChConfigVars->ChannelMode & 0b01) );
        BITS_SET(DMA->Channel[ChNum].CCR, DIR, (Copy_pstrChConfigVars->ChannelMode & 0b10) );

        // channel priority
        BITS_SET(DMA->Channel[ChNum].CCR, PL0, Copy_pstrChConfigVars->ChannelPriority);

        // channel channel size
        BITS_SET(DMA->Channel[ChNum].CCR, MSIZE0, Copy_pstrChConfigVars->ChannelSize);
        BITS_SET(DMA->Channel[ChNum].CCR, PSIZE0, Copy_pstrChConfigVars->PeripheralSize);
        
        // channel increment mode
        BITS_SET(DMA->Channel[ChNum].CCR, MINC, Copy_pstrChConfigVars->IncrementMode);
        BITS_SET(DMA->Channel[ChNum].CCR, PINC, Copy_pstrChConfigVars->IncrementMode);

        // channel circular mode
        BITS_SET(DMA->Channel[ChNum].CCR, CIRC, Copy_pstrChConfigVars->CircularMode);
    }
    
    return Local_ErrorState;
}   

ERROR_STATE_t DMA_u8ChannelTransfer(DMA_ConfigVars_t* Copy_pstrChannelConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u32 Copy_u32TransfersNumber)
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    return Local_ErrorState;
}


ERROR_STATE_t DMA_u8ChannelTransferBusy(DMA_ConfigVars_t* Copy_pstrChannelConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u32 Copy_u32TransfersNumber)
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    return Local_ErrorState;
}


ERROR_STATE_t DMA_u8SetInterruptCallBack(DMA_ConfigVars_t* Copy_pstrChannelConfigVars,void (*pf)(void))
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    return Local_ErrorState;
}