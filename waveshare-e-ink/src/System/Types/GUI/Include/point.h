// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com

#ifndef SRC_SYSTEM_TYPES_GUI_POINT_H_
#define SRC_SYSTEM_TYPES_GUI_POINT_H_

namespace GUI {

template <class T>
class Point
{
private:
	T _ValueX;
	T _ValueY;

public:
	Point();
	Point(T x, T y);
	virtual ~Point();

	T GetX();
	T GetY();

	T SetX(T value);
	T SetY(T value);

	T AddX(T value = 1);
	T AddY(T value = 1);

	T SubX(T value = 1);
	T SubY(T value = 1);
};

} /* namespace Drivers */

#include "../point.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_POINT_H_ */
