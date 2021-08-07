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
        
        // channel transfer mode
        if (Copy_pstrChConfigVars->ChannelMode == DMA_ChMode_MemoryToPeripheral)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, MEM2MEM);
            SET_BIT(DMA->Channel[ChNum].CCR, DIR);
        }
        else if (Copy_pstrChConfigVars->ChannelMode == DMA_ChMode_PeripheralToMemory)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, MEM2MEM);
            CLR_BIT(DMA->Channel[ChNum].CCR, DIR);
        }
        else if (Copy_pstrChConfigVars->ChannelMode == DMA_ChMode_MemoryToMemory)
        {
            SET_BIT(DMA->Channel[ChNum].CCR, MEM2MEM);
            CLR_BIT(DMA->Channel[ChNum].CCR, DIR);
        }

        // channel priority
        if (Copy_pstrChConfigVars->ChannelPriority == DMA_ChPriority_Low)
        {
            CLR_BITS(DMA->Channel[ChNum].CCR, PL0, 0b00);
        }
        else if (Copy_pstrChConfigVars->ChannelPriority == DMA_ChPriority_Medium)
        {
            SET_BIT(DMA->Channel[ChNum].CCR, PL0);
            CLR_BIT(DMA->Channel[ChNum].CCR, PL1);
        }
        else if (Copy_pstrChConfigVars->ChannelPriority == DMA_ChPriority_High)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, PL0);
            SET_BIT(DMA->Channel[ChNum].CCR, PL1);
        }
        else if (Copy_pstrChConfigVars->ChannelPriority == DMA_ChPriority_VeryHigh)
        {
            SET_BITS(DMA->Channel[ChNum].CCR, PL0, 0b11);
        }
        
        // channel channel size
        if (Copy_pstrChConfigVars->ChannelSize == DMA_ChSize_8Bits)
        {
            CLR_BITS(DMA->Channel[ChNum].CCR, MSIZE0, 0b00);
        }
        else if (Copy_pstrChConfigVars->ChannelSize == DMA_ChSize_16Bits)
        {
            SET_BIT(DMA->Channel[ChNum].CCR, MSIZE0);
            CLR_BIT(DMA->Channel[ChNum].CCR, MSIZE1);
        }
        else if (Copy_pstrChConfigVars->ChannelSize == DMA_ChSize_32Bits)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, MSIZE0);
            SET_BIT(DMA->Channel[ChNum].CCR, MSIZE1);
        }

        // channel peripheral size
        if (Copy_pstrChConfigVars->PeripheralSize == DMA_PeripheralSize_8Bits)
        {
            CLR_BITS(DMA->Channel[ChNum].CCR, PSIZE0, 0b00);
        }
        else if (Copy_pstrChConfigVars->PeripheralSize == DMA_PeripheralSize_16Bits)
        {
            SET_BIT(DMA->Channel[ChNum].CCR, PSIZE0);
            CLR_BIT(DMA->Channel[ChNum].CCR, PSIZE1);
        }
        else if (Copy_pstrChConfigVars->PeripheralSize == DMA_PeripheralSize_32Bits)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, PSIZE0);
            SET_BIT(DMA->Channel[ChNum].CCR, PSIZE1);
        }

        // channel increment mode
        if (Copy_pstrChConfigVars->IncrementMode == DMA_IncrementMode_IncrementDisable)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, MINC);
            CLR_BIT(DMA->Channel[ChNum].CCR, PINC);
        }
        else if (Copy_pstrChConfigVars->IncrementMode == DMA_IncrementMode_IncrementEnable)
        {
            SET_BIT(DMA->Channel[ChNum].CCR, MINC);
            SET_BIT(DMA->Channel[ChNum].CCR, PINC);
        }

        // channel circular mode
        if (Copy_pstrChConfigVars->CircularMode == DMA_CircularMode_Disable)
        {
            CLR_BIT(DMA->Channel[ChNum].CCR, CIRC);
        }
        else if (Copy_pstrChConfigVars->IncrementMode == DMA_CircularMode_Enable)
        {
            SET_BIT(DMA->Channel[ChNum].CCR, CIRC);
        }
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