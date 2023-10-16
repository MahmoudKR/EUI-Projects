/*
 * DIO.h
 *
 *  Created on: Oct 14, 2023
 *      Author: eme
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

typedef Uint8_t Dio_LevelType;
typedef Uint8_t Dio_PortType;
typedef Uint8_t Dio_ChannelType;


#define STD_HIGH  (Dio_LevelType)1
#define STD_LOW  (Dio_LevelType)0

#define PORTA (Dio_PortType)0
#define PORTB (Dio_PortType)1
#define PORTC (Dio_PortType)2
#define PORTD (Dio_PortType)3
#define PORTE (Dio_PortType)4
#define PORTF (Dio_PortType)5

void port_init (void);

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);

#endif /* MCAL_DIO_DIO_H_ */
