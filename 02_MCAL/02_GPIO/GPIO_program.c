#include<STD_TYPES.h>
#include<BIT_MATH.h>

#include<GPIO_interface.h>
#include<GPIO_private.h>
#include<stm32f103xx.h>

ERROR_STATE_t GPIO_u8PinMode(GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, u8 Copy_u8Mode)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if ( !(Copy_u8PortAddress < GPIOA) || !(Copy_u8PortAddress > GPIOG))
    {
        // enable GPIO bus
        GPIO_Privateu8EnableBus(Copy_u8PortAddress);

        //checks if pin falls in CRL
        if (Copy_u8PinNumber > GPIO_u8Pin7)
        {
            // clear bits
            CLR_BITS(Copy_u8PortAddress->CRL, (Copy_u8PinNumber * 4), 0b1111 );

            // multiply pin number by 4 to set it propper bit in the register
            // 0b01111 is a mask for MODEx and CNFx bits 
            SET_BITS(Copy_u8PortAddress->CRL, (Copy_u8PinNumber * 4), (Copy_u8Mode & 0b01111) );
        }
        // if pin falls in CRH
        else if(Copy_u8PinNumber < GPIO_u8Pin15)
        {
            // clear bits
            CLR_BITS(Copy_u8PortAddress->CRH, ( (Copy_u8PinNumber - 8) * 4), 0b1111 );

            // subtract 8 from the pin number to map it to the CRH register starting from 0
            SET_BITS(Copy_u8PortAddress->CRH, ( (Copy_u8PinNumber - 8) * 4), (Copy_u8Mode & 0b01111) );
        }
        else
        {
            Local_u8ErrorState = STD_TYPES_NOK;
        }

        // set ODR register for pul-up or pull-down functionality
        if (Copy_u8Mode & 0b10000)
        {
            SET_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);
        }
        else
        {
            CLR_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);
        }

    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t GPIO_u8PinWrite  (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t Copy_u8Value)
{
    if (Copy_u8Value)
    {
        SET_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);
    }
    else
    {
        CLR_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);
    }
}
ERROR_STATE_t GPIO_u8PinRead   (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t* Copy_u8ReturnValue)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    *Copy_u8ReturnValue = GET_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);

    return Local_u8ErrorState;
}
ERROR_STATE_t GPIO_u8PinToggle (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    TOG_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);

    return Local_u8ErrorState;
}

ERROR_STATE_t GPIO_Privateu8EnableBus(GPIO_REGISTERS_t* Copy_u8PortAddress)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;
    
    if (Copy_u8PortAddress == GPIOA)
    {
        RCC_u8EnablePeripheralBus(GPIOA_u8Bus, IOPAEN);
    }
    else if (Copy_u8PortAddress == GPIOB)
    {
        RCC_u8EnablePeripheralBus(GPIOB_u8Bus, IOPBEN);
    }
    else if (Copy_u8PortAddress == GPIOC)
    {
        RCC_u8EnablePeripheralBus(GPIOC_u8Bus, IOPCEN);
    }
    else if (Copy_u8PortAddress == GPIOD)
    {
        RCC_u8EnablePeripheralBus(GPIOD_u8Bus, IOPDEN);
    }
    else if (Copy_u8PortAddress == GPIOE)
    {
        RCC_u8EnablePeripheralBus(GPIOE_u8Bus, IOPEEN);
    }
    else if (Copy_u8PortAddress == GPIOF)
    {
        RCC_u8EnablePeripheralBus(GPIOF_u8Bus, IOPFEN);
    }
    else if (Copy_u8PortAddress == GPIOG)
    {
        RCC_u8EnablePeripheralBus(GPIOG_u8Bus, IOPGEN);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}