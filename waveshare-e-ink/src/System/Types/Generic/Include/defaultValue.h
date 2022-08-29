// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GENERIC_DEFAULTVALUE_H_
#define SRC_SYSTEM_TYPES_GENERIC_DEFAULTVALUE_H_


#include "value.h"


#pragma once


namespace OS {
namespace Types {
namespace Generic {

template <class T>
class DefaultValue : public Value<T>
{
private:
	T _Default;

public:
	DefaultValue();
	virtual ~DefaultValue();

	virtual void Reset();

	virtual T GetDefault();
	virtual T SetDefault(T value);

};

}}}

#include "../defaultValue.tpp"

#endif /* SRC_SYSTEM_TYPES_GENERIC_DEFAULTVALUE_H_ */
