#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


ERROR_STATE_t GPIO_u8PinMode   (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, u8 Copy_u8Mode);
ERROR_STATE_t GPIO_u8PinWrite  (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t Copy_u8Value);
ERROR_STATE_t GPIO_u8PinRead   (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber, PIN_VALUE_t* Copy_u8ReturnValue);
ERROR_STATE_t GPIO_u8PinToggle (GPIO_REGISTERS_t* Copy_u8PortAddress, GPIO_u8PinNumber Copy_u8PinNumber);


#endif