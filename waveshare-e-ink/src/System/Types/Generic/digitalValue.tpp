// Copyright (c) 2022 Lukin Aleksandr
#include "digitalValue.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
DigitalValue<T>::DigitalValue()
	: DefaultValue<T>(), ZeroCompareEx<T>(), ValueCompareEx<T>()
{
	Value<T>::SetValue(0);
	DefaultValue<T>::SetDefault(0);
}

template <class T>
T DigitalValue<T>::GetValue()
{
	return Value<T>::GetValue();
}

template <class T>
T DigitalValue<T>::operator++()
{
	T value = GetValue();
	return Value<T>::SetValue(++value);
}

template <class T>
T DigitalValue<T>::operator--()
{
	T value = GetValue();
	return Value<T>::SetValue(--value);
}

template <class T>
DigitalValue<T>::~DigitalValue()
{

}

}}}
