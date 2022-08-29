// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "zeroCompareEx.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
ZeroCompareEx<T>::ZeroCompareEx()
{

}

template <class T>
bool ZeroCompareEx<T>::IsNull()
{
	return (GetValue() == 0);
}

template <class T>
bool ZeroCompareEx<T>::IsNotNull()
{
	return (GetValue() != 0);
}

template <class T>
ZeroCompareEx<T>::~ZeroCompareEx()
{

}

}}}
