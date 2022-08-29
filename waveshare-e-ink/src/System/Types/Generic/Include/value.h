// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef MAIN_OS_TYPES_GENERIC_VALUE_H_
#define MAIN_OS_TYPES_GENERIC_VALUE_H_

#pragma once

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class Value {
private:
	T _Value;

public:
	Value();
	virtual ~Value();

	virtual T GetValue();
	virtual T SetValue(T value);

	virtual bool operator==(Value& value);

};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../value.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_VALUE_H_ */
