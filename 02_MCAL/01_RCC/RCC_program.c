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
        SET_BIT(RCC->CR, HSION);
        SET_BITS(RCC->CFGR, SW, HSI);

    #elif (RCC_SYSTEM_CLOCK == HSE)
        SET_BIT(RCC->CR, HSEON);
        SET_BITS(RCC->CFGR, SW, HSE);
        RCC_u8SetClockSecuritySystem();

    #elif (RCC_SYSTEM_CLOCK == PLL)
        SET_BIT(RCC->CR, PLLON);
        SET_BITS(RCC->CFGR, SW, PLL);
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
        SET_BIT(RCC->CFGR, PLLSRC);

    #else (RCC_PLL_CLOCK_SOURCE == PLL_HSI)
        CLR_BIT(RCC->CFGR, PLLSRC);

    #endif

    return Local_u8ErrorState;
}

ERROR_STATE_t Private_u8SetClockSecuritySystem(void)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    #if RCC_CLOCK_SECURITY_SYSTEM == CSS_OFF
        CLR_BIT(RCC->CR, CSSON);

    #else
        SET_BIT(RCC->CR, CSSON);

    #endif

    return Local_u8ErrorState;
}

ERROR_STATE_t RCC_u8MCUClockOutput(u8 Copy_u8OutPutSource)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    SET_BITS(RCC->CFGR, MCO, Copy_u8OutPutSource);
    if (GET_BITS(RCC->CFGR, MCO, 0b111) != Copy_u8OutPutSource)
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
            SET_BIT(RCC->AHBENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB1_BUS:
            SET_BIT(RCC->APB1ENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB2_BUS:
            SET_BIT(RCC->APB2ENR, Copy_u8Peripheral);
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
            CLR_BIT(RCC->AHBENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB1_BUS:
            CLR_BIT(RCC->APB1ENR, Copy_u8Peripheral);
            break;
        
        case STM32_u8APB2_BUS:
            CLR_BIT(RCC->APB2ENR, Copy_u8Peripheral);
            break;
        
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
            break;
        }
    }

    return Local_u8ErrorState;
}