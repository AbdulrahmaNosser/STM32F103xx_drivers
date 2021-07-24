#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


ERROR_STATE_t GPIO_PinMode   (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, u8 Copy_u8Mode);
ERROR_STATE_t GPIO_PinWrite  (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t Copy_u8Value);
ERROR_STATE_t GPIO_PinRead   (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t* Copy_u8ReturnValue);
ERROR_STATE_t GPIO_PinToggle (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber);


#endif