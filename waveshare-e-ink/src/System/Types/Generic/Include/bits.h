// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SYSTEM_TYPES_GENERIC_BITS_H_
#define SYSTEM_TYPES_GENERIC_BITS_H_

#pragma once

#define __SET_BIT(Value, Bit) 			(Value |= (1 << Bit))
#define	__RESET_BIT( Value, Bit )		(Value &= (~(1 << Bit)))
#define __LOGICAL_OR(Value,Mask,Bit)	(Value |= (Mask << Bit))
#define __GET_BIT(Value,Bit)    		(((1 << Bit) & Value) >> Bit)
#define __IS_SET_BIT(Value,Bit) 		((bool)((1 << Bit) & Value))

#endif /* SYSTEM_TYPES_GENERIC_BITS_H_ */
