// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef MAIN_OS_TYPES_GENERIC_RANGE_H_
#define MAIN_OS_TYPES_GENERIC_RANGE_H_

#pragma once

#include "digitalValue.h"
#include "PreCompiller.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class Range {
private:
	shared_ptr<DigitalValue<T>> _Min;
	shared_ptr<DigitalValue<T>> _Max;

public:
	Range();
	virtual ~Range();

	shared_ptr<DigitalValue<T>> Min();
	shared_ptr<DigitalValue<T>> Max();

	bool IsInRange(T value);

protected:
	virtual bool IsSetRange();

};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../range.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_RANGE_H_ */
