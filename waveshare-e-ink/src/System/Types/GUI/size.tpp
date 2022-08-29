// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "size.h"

namespace GUI {

template <class T>
Size<T>::Size()
  :_Width(0), _Height(0)
{
	

}

template <class T>
Size<T>::Size(T width, T height)
  :_Width(width), _Height(height)
{

}

template <class T>
T Size<T>::GetWidth()  const
{
	return _Width;
}

template <class T>
void Size<T>::SetWidth (T value)
{
	_Width = value;
}

template <class T>
T Size<T>::GetHeight() const
{
	return _Height;
}

template <class T>
void Size<T>::SetHeight(T value)
{
	_Height = value;
}

template <class T>
Size<T>::~Size()
{

}

}
