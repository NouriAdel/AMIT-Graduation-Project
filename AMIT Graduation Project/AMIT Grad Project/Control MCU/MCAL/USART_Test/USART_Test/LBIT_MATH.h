
/*File guard*/
#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

/*Bit manipulation functions*/
#define SET_BIT(VAR, BIT)     VAR |= (1 << BIT) 
#define CLEAR_BIT(VAR, BIT)   VAR &= ~(1 << BIT)
#define TOGGLE_BIT(VAR, BIT)  VAR ^= (1 << BIT)
#define GET_BIT(VAR, BIT)     ((VAR >> BIT) & 1) 

#endif /*__BIT_MATH_H__*/