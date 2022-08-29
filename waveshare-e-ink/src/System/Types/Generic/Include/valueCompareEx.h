// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef MAIN_OS_TYPES_GENERIC_VALUECOMPAREEX_H_
#define MAIN_OS_TYPES_GENERIC_VALUECOMPAREEX_H_

#pragma once

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class ValueCompareEx
{
public:
	ValueCompareEx();
	virtual ~ValueCompareEx();

	virtual T GetValue() = 0;

	virtual bool IsMore(T value);
	virtual bool IsMoreOrEqual(T value);
	virtual bool IsLess(T value);
	virtual bool IsLessOrEqual(T value);
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../valueCompareEx.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_VALUECOMPAREEX_H_ */
