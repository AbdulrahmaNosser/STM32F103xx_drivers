#include<STD_TYPES.h>
#include<BIT_MATH.h>

#include<stm32f103xx.h>

#include<GPIO_interface.h>
#include<GPIO_private.h>


ERROR_STATE_t GPIO_PinMode(GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, u8 Copy_u8Mode)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if ( !(Copy_u8PortAddress < GPIOA) || !(Copy_u8PortAddress > GPIOG))
    {
        //checks if pin falls in CRL
        if (Copy_u8PinNumber <= GPIO_u8Pin7)
        {
            // clear bits
            CLR_BITS(Copy_u8PortAddress->CRL, (Copy_u8PinNumber * 4), 0b0000 );

            // multiply pin number by 4 to set it propper bit in the register
            // 0b01111 is a mask for MODEx and CNFx bits 
            SET_BITS(Copy_u8PortAddress->CRL, (Copy_u8PinNumber * 4), (Copy_u8Mode & 0b01111) );
        }
        // if pin falls in CRH
        else if(Copy_u8PinNumber < GPIO_u8Pin15)
        {
            // clear bits
            CLR_BITS(Copy_u8PortAddress->CRH, ( (Copy_u8PinNumber - 8) * 4), 0b0000 );

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

ERROR_STATE_t GPIO_PinWrite  (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t Copy_u8Value)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if ( !(Copy_u8PortAddress < GPIOA) || !(Copy_u8PortAddress > GPIOG))
    {
        if (Copy_u8Value)
        {
            SET_BIT(Copy_u8PortAddress->BSRR, Copy_u8PinNumber);
        }
        else
        {
            SET_BIT(Copy_u8PortAddress->BRR, Copy_u8PinNumber);
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t GPIO_PinRead   (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t* Copy_u8ReturnValue)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if ( !(Copy_u8PortAddress < GPIOA) || !(Copy_u8PortAddress > GPIOG))
    {
        *Copy_u8ReturnValue = GET_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}

ERROR_STATE_t GPIO_PinToggle (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber)
{
    ERROR_STATE_t Local_u8ErrorState = STD_TYPES_OK;

    if ( !(Copy_u8PortAddress < GPIOA) || !(Copy_u8PortAddress > GPIOG))
    {
        TOG_BIT(Copy_u8PortAddress->ODR, Copy_u8PinNumber);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}
