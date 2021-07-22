#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


u8 GPIO_u8PinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
u8 GPIO_u8PinWrite(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 GPIO_u8PinRead(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8ReturnValue);
u8 GPIO_u8PinToggle(u8 Copy_u8Port, u8 Copy_u8Pin);

enum GPIO_MODE
{
    PIN_MODE_INPUTE_ANALOG,
    PIN_MODE_INPUTE_FLOATING,
    PIN_MODE_INPUTE_PULL,
    PIN_MODE_OUTPUT_G,
    PIN_MODE_INPUTE_ANALOG,

};

#endif