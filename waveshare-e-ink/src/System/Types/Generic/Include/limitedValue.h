// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef MAIN_OS_TYPES_GENERIC_LIMITEDVALUE_H_
#define MAIN_OS_TYPES_GENERIC_LIMITEDVALUE_H_

#pragma once

#include "range.h"
#include "PreCompiller.h"



namespace OS {
namespace Types {
namespace Generic {

template <class T>
class LimitedValue :public Range<T>,  public DigitalValue<T>
{
private:
	bool _IsMinLimit;
	bool _IsMaxLimit;

public:
	LimitedValue();
	virtual ~LimitedValue();

	virtual T operator++() override;
	virtual T operator--() override;

	bool IsMaxLimit();
	bool IsMinLimit();

	void Reset() override;

	virtual T SetValue(T value) override;

	virtual T SetMinValue();
	virtual T SetMaxValue();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../limitedValue.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_LIMITEDVALUE_H_ */
