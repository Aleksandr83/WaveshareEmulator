// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef MAIN_OS_TYPES_GENERIC_DIGITALVALUE_H_
#define MAIN_OS_TYPES_GENERIC_DIGITALVALUE_H_

#pragma once

#include "defaultValue.h"
#include "zeroCompareEx.h"
#include "valueCompareEx.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class DigitalValue
	: public DefaultValue<T>, public ZeroCompareEx<T>, public ValueCompareEx<T>
{
public:
	DigitalValue();
	virtual ~DigitalValue();

	virtual T GetValue() override;

	virtual T operator++();
	virtual T operator--();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../digitalValue.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_DIGITALVALUE_H_ */
