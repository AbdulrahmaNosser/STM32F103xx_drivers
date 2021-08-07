#include<STD_TYPES.h>
#include<BIT_MATH.h>
#include<stm32f103xx.h>

#include<DMA_private.h>
#include<DMA_interface.h>

typedef void (*fptr_t)(void);

fptr_t Global_pfArr[7] = {NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t, NULL_p_t};

ERROR_STATE_t DMA_u8ChannelInit(DMA_ConfigVars_t* Copy_pstrChConfigVars)
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    if (Copy_pstrChConfigVars != NULL_p_t)
    {
        Local_ErrorState = STD_TYPES_OK;
        u8 ChNum = Copy_pstrChConfigVars->ChannelNumber - 1;

        // clear register bits
        BITS_CLR(DMA->Channel[ChNum].CCR, DIR, 0x800 );

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

ERROR_STATE_t DMA_u8ChannelTransfer(DMA_ConfigVars_t* Copy_pstrChConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u16 Copy_u16TransfersNumber)
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    u8 ChNum = Copy_pstrChConfigVars->ChannelNumber - 1;
    
    // set source and destination addresses
    switch (Copy_pstrChConfigVars->ChannelMode)
    {
    case DMA_ChMode_PeripheralToMemory:
        BITS_SET(DMA->Channel[ChNum].CPAR, 0, Copy_u32Source);
        BITS_SET(DMA->Channel[ChNum].CMAR, 0, Copy_u32Destination);
        break;

    case DMA_ChMode_MemoryToMemory:
        BITS_SET(DMA->Channel[ChNum].CPAR, 0, Copy_u32Source);
        BITS_SET(DMA->Channel[ChNum].CMAR, 0, Copy_u32Destination);

    case DMA_ChMode_MemoryToPeripheral:
        BITS_SET(DMA->Channel[ChNum].CPAR, 0, Copy_u32Destination);
        BITS_SET(DMA->Channel[ChNum].CMAR, 0, Copy_u32Source);
        break;
    
    default:
        break;
    }

    // sets number of transfers
    BITS_SET(DMA->Channel[ChNum].CNDTR, 0, Copy_u16TransfersNumber);

    // enables the channel to start transmition
    BIT_SET(DMA->Channel[ChNum].CCR, EN);

    return Local_ErrorState;
}


ERROR_STATE_t DMA_u8ChannelTransferBusy(DMA_ConfigVars_t* Copy_pstrChConfigVars, u32 Copy_u32Source, u32 Copy_u32Destination, u16 Copy_u16TransfersNumber)
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    u8 ChNum = Copy_pstrChConfigVars->ChannelNumber - 1;
    
    // set source and destination addresses
    switch (Copy_pstrChConfigVars->ChannelMode)
    {
    case DMA_ChMode_PeripheralToMemory:
        BITS_SET(DMA->Channel[ChNum].CPAR, 0, Copy_u32Source);
        BITS_SET(DMA->Channel[ChNum].CMAR, 0, Copy_u32Destination);
        break;

    case DMA_ChMode_MemoryToMemory:
        BITS_SET(DMA->Channel[ChNum].CPAR, 0, Copy_u32Source);
        BITS_SET(DMA->Channel[ChNum].CMAR, 0, Copy_u32Destination);

    case DMA_ChMode_MemoryToPeripheral:
        BITS_SET(DMA->Channel[ChNum].CPAR, 0, Copy_u32Destination);
        BITS_SET(DMA->Channel[ChNum].CMAR, 0, Copy_u32Source);
        break;
    
    default:
        break;
    }

    // sets number of transfers
    BITS_SET(DMA->Channel[ChNum].CNDTR, 0, Copy_u16TransfersNumber);

    // wait for data transfer completion then clear the flag
    u8 Local_TCIFx = (ChNum * 3) + 4;
    while(!BIT_GET(DMA->ISR, Local_TCIFx - 1))
    {
        BIT_SET(DMA->ISR, Local_TCIFx);
    }

    return Local_ErrorState;
}


ERROR_STATE_t DMA_u8SetInterruptCallBack(DMA_ConfigVars_t* Copy_pstrChConfigVars,void (*pf)(void))
{
    ERROR_STATE_t Local_ErrorState = STD_TYPES_NOK;

    if (pf != NULL_p_t)
    {
        Global_pfArr[Copy_pstrChConfigVars->ChannelNumber - 1] = pf;
        Local_ErrorState = STD_TYPES_OK;
    }
    
    return Local_ErrorState;
}


void DMA1_Channel1_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF1);
    if (Global_pfArr[0] != NULL_p_t)
    {
        Global_pfArr[0]();
    }
}

void DMA1_Channel2_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF2);
    if (Global_pfArr[1] != NULL_p_t)
    {
        Global_pfArr[1]();
    }
}

void DMA1_Channel3_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF3);
    if (Global_pfArr[2] != NULL_p_t)
    {
        Global_pfArr[2]();
    }
}

void DMA1_Channel4_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF4);
    if (Global_pfArr[3] != NULL_p_t)
    {
        Global_pfArr[3]();
    }
}

void DMA1_Channel5_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF5);
    if (Global_pfArr[4] != NULL_p_t)
    {
        Global_pfArr[4]();
    }
}

void DMA1_Channel6_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF6);
    if (Global_pfArr[5] != NULL_p_t)
    {
        Global_pfArr[5]();
    }
}

void DMA1_Channel7_IRQHandler(void)
{
    BIT_SET(DMA->ISR, TCIF7);
    if (Global_pfArr[6] != NULL_p_t)
    {
        Global_pfArr[6]();
    }
}
