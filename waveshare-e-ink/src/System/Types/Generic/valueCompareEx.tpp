// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "valueCompareEx.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
ValueCompareEx<T>::ValueCompareEx()
{

}

template <class T>
bool ValueCompareEx<T>::IsMore(T value)
{
	return (GetValue() > value);
}

template <class T>
bool ValueCompareEx<T>::IsMoreOrEqual(T value)
{
	return (GetValue() >= value);
}

template <class T>
bool ValueCompareEx<T>::IsLess(T value)
{
	return (GetValue() < value);
}

template <class T>
bool ValueCompareEx<T>::IsLessOrEqual(T value)
{
	return (GetValue() <= value);
}

template <class T>
ValueCompareEx<T>::~ValueCompareEx()
{

}

}}}
