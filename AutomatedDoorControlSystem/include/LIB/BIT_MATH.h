/*
 * BIT_MATH.h
 *
 * Created: 2/29/2024 1:00:00 PM
 * Author: Tarek Alaa
 */ 

#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

//SET_BIT to make value of bit (1)
#define SET_BIT(REG,BITN)  (REG|=(1<<BITN))
//CLR_BIT to make value of bit (0)
#define CLR_BIT(REG,BITN)  (REG&=~(1<<BITN))
//TOGG_BIT to change value of bit from (1) to (0) and from (0) to (1)
#define TOGG_BIT(REG,BITN) (REG^=(1<<BITN))
//READ_BIT to read value of bit
#define GET_BIT(REG,BITN) ((REG>>BITN)&0x01)

#endif // BIT_MATH_H_INCLUDED
