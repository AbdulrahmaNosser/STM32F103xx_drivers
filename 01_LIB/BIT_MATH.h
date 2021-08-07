#ifndef BIT_MATH_H
#define BIT_MATH_H

#define BIT_SET(REGISTER, BIT) (REGISTER |=  (1<<BIT))
#define BIT_CLR(REGISTER, BIT) (REGISTER &= ~(1<<BIT))
#define BIT_TOG(REGISTER, BIT) (REGISTER ^=  (1<<BIT))
#define BIT_GET(REGISTER, BIT) ((REGISTER>>BIT)&1)

#define BITS_SET(REGISTER, BIT, VALUE) (REGISTER |=  (VALUE<<BIT))
#define BITS_CLR(REGISTER, BIT, VALUE) (REGISTER &= ~(~VALUE<<BIT))
#define BITS_TOG(REGISTER, BIT, VALUE) (REGISTER ^=  (VALUE<<BIT))
#define BITS_CLR(REGISTER, BIT, VALUE) ((REGISTER>>BIT)&VALUE)

#define BIT_SET_ATOMIC(REGISTER) (REGISTER =  1)
#define BIT_CLR_ATOMIC(REGISTER) (REGISTER =  0)
#define BIT_TOG_ATOMIC(REGISTER) (REGISTER ^= 1)
#define BIT_GET_ATOMIC(REGISTER) (REGISTER &  1)

#endif