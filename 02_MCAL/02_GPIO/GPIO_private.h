#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


enum GPIOx_CRL_BITS
{
    MODE0,
    MODE0_1,
    CNF0,
    CNF0_1,
    
    MODE1,
    MODE1_1,
    CNF1,
    CNF1_1,

    MODE2,
    MODE2_1,
    CNF2,
    CNF2_1,

    MODE3,
    MODE3_1,
    CNF3,
    CNF3_1,

    MODE4,
    MODE4_1,
    CNF4,
    CNF4_1,

    MODE5,
    MODE5_1,
    CNF5,
    CNF5_1,

    MODE6,
    MODE6_1,
    CNF6,
    CNF6_1,

    MODE7,
    MODE7_1,
    CNF7,
    CNF7_1,
};

enum GPIOx_CRH_BITS
{
    MODE8,
    MODE8_1,
    CNF8,
    CNF8_1,
    
    MODE9,
    MODE9_1,
    CNF9,
    CNF9_1,

    MODE10,
    MODE10_1,
    CNF10,
    CNF10_1,

    MODE11,
    MODE11_1,
    CNF11,
    CNF11_1,

    MODE12,
    MODE12_1,
    CNF12,
    CNF12_1,

    MODE13,
    MODE13_1,
    CNF13,
    CNF13_1,

    MODE14,
    MODE14_1,
    CNF14,
    CNF14_1,

    MODE15,
    MODE15_1,
    CNF15,
    CNF15_1,
};


ERROR_STATE_t GPIO_Privateu8EnableBus(GPIO_REGISTERS_t* GPIO_u8CopyPortAddress);


#endif