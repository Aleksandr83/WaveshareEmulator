// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef MAIN_OS_TYPES_GENERIC_INCLUDE_ZEROCOMPAREEX_H_
#define MAIN_OS_TYPES_GENERIC_INCLUDE_ZEROCOMPAREEX_H_

#pragma once

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class ZeroCompareEx {
public:
	ZeroCompareEx();
	virtual ~ZeroCompareEx();

	virtual T GetValue() = 0;

	virtual bool IsNull();
	virtual bool IsNotNull();

};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../zeroCompareEx.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_INCLUDE_ZEROCOMPAREEX_H_ */
