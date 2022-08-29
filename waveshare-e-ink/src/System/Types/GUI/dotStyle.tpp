// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "dotStyle.h"

namespace GUI {

template <class T>
DotStyle<T>::DotStyle()
  :_DotStyle(1)
{

}

template <class T>
T DotStyle<T>::GetDotStyle() const
{
	return _DotStyle;
}

template <class T>
void  DotStyle<T>::SetDotStyle (T dotStyle)
{
	_DotStyle = dotStyle;
}

template <class T>
DotStyle<T>::~DotStyle()
{

}

}
