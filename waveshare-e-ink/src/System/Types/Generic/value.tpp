// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "value.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
Value<T>::Value()
{

}

template <class T>
T Value<T>::GetValue()
{
	return _Value;
}

template <class T>
T Value<T>::SetValue(T value)
{
	_Value = value;
	return _Value;
}

template <class T>
bool Value<T>::operator==(Value& value)
{
	return (_Value == value.GetValue());
}

template <class T>
Value<T>::~Value()
{

}

}}}
