// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "point.h"

namespace GUI {

template <class T>
Point<T>::Point()
  :_ValueX(0), _ValueY(0)
{

}

template <class T>
Point<T>::Point(T x, T y)
  :_ValueX(x), _ValueY(y)
{

}

template <class T>
T Point<T>::GetX()
{
	return _ValueX;
}

template <class T>
T Point<T>::GetY()
{
	return _ValueY;
}

template <class T>
T Point<T>::SetX(T value)
{
	return _ValueX = value;
}

template <class T>
T Point<T>::SetY(T value)
{
	return _ValueY = value;
}

template <class T>
T Point<T>::AddX(T value)
{
	return _ValueX += value;
}

template <class T>
T Point<T>::AddY(T value)
{
	return _ValueY += value;
}

template <class T>
T Point<T>::SubX(T value)
{
	return _ValueX -= value;
}

template <class T>
T Point<T>::SubY(T value)
{
	return _ValueY -= value;
}

template <class T>
Point<T>::~Point()
{

}


} /* namespace Drivers */


