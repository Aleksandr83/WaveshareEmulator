// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef OS_TYPES_GENERIC_COUNTER_H_
#define OS_TYPES_GENERIC_COUNTER_H_

#pragma once

#include "limitedValue.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class Counter : public LimitedValue<T>
{
private:
	bool _IsCyclic;

public:
	Counter();
	virtual ~Counter();

	virtual void Inc();
	virtual void Dec();

	virtual T operator++() override;
	virtual T operator--() override;

	virtual void SetCyclicValue(bool value);
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../counter.tpp"

#endif /* OS_TYPES_GENERIC_COUNTER_H_ */
