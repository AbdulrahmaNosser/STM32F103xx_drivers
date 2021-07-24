#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int  u16;
typedef signed short int    s16;
typedef unsigned long int   u32;
typedef signed long int     s32;
typedef float               f32;
typedef double              f64;
typedef long double         f128;

typedef enum
{
    STD_TYPES_NOK,
    STD_TYPES_OK
}ERROR_STATE_t;

typedef enum
{
    STD_TYPES_LOW,
    STD_TYPES_HIGH
}PIN_VALUE_t;

#define NULL_p_t ((void*)0) 
#endif