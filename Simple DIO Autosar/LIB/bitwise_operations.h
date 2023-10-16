/*
 * bitwise_operations.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef BITWISE_OPERATIONS_H_
#define BITWISE_OPERATIONS_H_
#define port_f GPIO_PORTF_DATA_BITS_R

#define Set_bit(Register,bit) ((Register)|=(Uint32_t)(1<<bit))
#define Clear_bit(Register,bit) ((Register)&=~(Uint32_t)(1<<bit))
#define Get_bit(Register,bit) ((Register)&(Uint32_t)(1<<bit))
#define Toggle_bit(Register,bit) ((Register)^=(Uint32_t)(1<<bit))
#define Set_reg(Register) ((Register)=(Uint32_t)0xFF))
#define Clear_reg(Register) ((Register)=(Uint32_t)0))

#define pin(x) (1<<x)

#define set_banding(Register,bit) (Register[(bit)]=(bit))
#define clear_banding(Register,bit) (Register[(Uint32_t)(1<<bit)] = 0)


#endif /* BITWISE_OPERATIONS_H_ */
