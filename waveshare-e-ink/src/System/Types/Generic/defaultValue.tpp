// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "defaultValue.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
DefaultValue<T>::DefaultValue()
  :Value<T>()
{

}

template <class T>
void DefaultValue<T>::Reset()
{
	Value<T>::SetValue(GetDefault());
}

template <class T>
T DefaultValue<T>::GetDefault()
{
	return _Default;
}

template <class T>
T DefaultValue<T>::SetDefault(T value)
{
	_Default = value;
	return _Default;
}

template <class T>
DefaultValue<T>::~DefaultValue()
{

}

}}}
