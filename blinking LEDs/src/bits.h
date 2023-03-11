#ifndef __BITS_H__
#define __BITS_H__


//--------
// MACROS
//--------

#define MODIFY_REG(reg, modifymask, value) (*(reg) = ((*(reg) & (~(modifymask))) | (value & modifymask)))
#define SET_BIT_ON(reg, bit)  (*(reg) |= 1U << (bit))       // set bit in register to 1
#define SET_BIT_OFF(reg, bit) (*(reg) &= (~(1U << (bit))))  // set bit in register to 0

#endif
