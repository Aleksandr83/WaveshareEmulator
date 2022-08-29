// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "dotPixel.h"

namespace GUI {

template <class T>
DotPixel<T>::DotPixel()
  :_DotPixel(1)
{

}

template <class T>
T DotPixel<T>::GetDotPixel() const
{
	return _DotPixel;
}

template <class T>
void DotPixel<T>::SetDotPixel(T dotPixel)
{
	_DotPixel = dotPixel;
}

template <class T>
DotPixel<T>::~DotPixel()
{

}


}
