#include<STD_TYPES.h>
#include<BIT_MATH.h>

#include<RCC_interface.h>


u8 RCC_u8SelectPLLSource(u8 Copy_PLLSource)
{
    switch (Copy_PLLSource)
    {
    case HSI:
        
    break;

    case HSE:
    
    break;

    case PLL:
    
    break;

    default:
        return 0;
        break;
    }
    
    return 1;
}

u8 RCC_u8SelectSystemClockSource(u8 Copy_u8ClockSource)
{
    switch (Copy_u8ClockSource)
    {
    case HSI:
        
    break;

    case HSE:
    
    break;

    case PLL:
    
    break;

    default:
        return 0;
        break;
    }
    
    return 1;
}

u8 RCC_u8EnablePeripheralBus(u8 Copy_u8BusName);