// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "lineStyle.h"

namespace GUI {

template <class T>
LineStyle<T>::LineStyle()
{

}

template <class T>
T LineStyle<T>::GetLineStyle() const
{
	return _LineStyle;
}

template <class T>
void LineStyle<T>::SetLineStyle(T lineStyle)
{
	_LineStyle = lineStyle;
}

template <class T>
LineStyle<T>::~LineStyle()
{

}

}
