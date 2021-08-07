#include<STD_TYPES.h>
#include<BIT_MATH.h>

#include<stm32f103xx.h>

#include<RCC_interface.h>
#include<RCC_private.h>
#include<RCC_config.h>


ERROR_STATE_t RCC_u8ClockInit(void)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    #if (RCC_SYSTEM_CLOCK == HSI)
        BIT_SET(RCC->CR, HSION);
        BITS_SET(RCC->CFGR, SW, HSI);

    #elif (RCC_SYSTEM_CLOCK == HSE)
        BIT_SET(RCC->CR, HSEON);
        BITS_SET(RCC->CFGR, SW, HSE);
        RCC_u8SetClockSecuritySystem();

    #elif (RCC_SYSTEM_CLOCK == PLL)
        BIT_SET(RCC->CR, PLLON);
        BITS_SET(RCC->CFGR, SW, PLL);
        RCC_u8SelectPLLSource();

    #else
        #error "Invalid clock source"

    #endif

    return Local_u8ErrorState;
}

ERROR_STATE_t Private_u8SelectPLLSource(void)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    #if   (RCC_PLL_CLOCK_SOURCE == PLL_HSE)
        BIT_SET(RCC->CFGR, PLLSRC);

    #else (RCC_PLL_CLOCK_SOURCE == PLL_HSI)
        BIT_CLR(RCC->CFGR, PLLSRC);

    #endif

    return Local_u8ErrorState;
}

ERROR_STATE_t Private_u8SetClockSecuritySystem(void)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    #if RCC_CLOCK_SECURITY_SYSTEM == CSS_OFF
        BIT_CLR(RCC->CR, CSSON);

    #else
        BIT_SET(RCC->CR, CSSON);

    #endif

    return Local_u8ErrorState;
}

ERROR_STATE_t RCC_u8MCUClockOutput(u8 Copy_u8OutPutSource)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    BITS_SET(RCC->CFGR, MCO, Copy_u8OutPutSource);
    if (BITS_CLR(RCC->CFGR, MCO, 0b111) != Copy_u8OutPutSource)
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    
    return Local_u8ErrorState;
}

ERROR_STATE_t RCC_u8EnablePeripheralBus(STM32_u8Bus_t Copy_u8Bus, u8 Copy_u8Peripheral)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if (Copy_u8Peripheral > 31)
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    else
    {
        switch (Copy_u8Bus)
        {
        case STM32_u8AHB_Bus:
            BIT_SET(RCC->AHBENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB1_BUS:
            BIT_SET(RCC->APB1ENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB2_BUS:
            BIT_SET(RCC->APB2ENR, Copy_u8Peripheral);
            break;
        
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
            break;
        }
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t RCC_u8DisablePeripheralBus(STM32_u8Bus_t Copy_u8Bus, u8 Copy_u8Peripheral)
{
        ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if (Copy_u8Peripheral > 31)
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    else
    {
        switch (Copy_u8Bus)
        {
        case STM32_u8AHB_Bus:
            BIT_CLR(RCC->AHBENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB1_BUS:
            BIT_CLR(RCC->APB1ENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB2_BUS:
            BIT_CLR(RCC->APB2ENR, Copy_u8Peripheral);
            break;
        
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
            break;
        }
    }

    return Local_u8ErrorState;
}