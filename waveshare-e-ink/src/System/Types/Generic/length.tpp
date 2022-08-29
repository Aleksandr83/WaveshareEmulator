// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "length.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
Length<T>::Length()
  :_Length(0)
{

}

template <class T>
T Length<T>::GetLength() const
{
  return _Length;
}

template <class T>
T Length<T>::SetLength(T value)
{
	return _Length = value;
}

template <class T>
Length<T>::~Length()
{

}

}}}
