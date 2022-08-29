// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "line.h"

namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
Line<T, TCanvas>::Line(GC<T, TCanvas>* gc, T x1, T y1, T x2, T y2)
  :Shape<T, TCanvas>(gc), LineStyle<T>(), _Point1(x1, y1), _Point2(x2, y2)
{

}

template <class T, class TCanvas>
void Line<T, TCanvas>::DrawFill()
{

}

template <class T, class TCanvas>
void Line<T, TCanvas>::DrawBorder()
{
	T dx   = abs(_Point2.GetX() - _Point1.GetX());
	T dy   = abs(_Point2.GetY() - _Point1.GetY());
	int sx = (_Point2.GetX() >= _Point1.GetX())? 1 : -1;
	int sy = (_Point2.GetY() >= _Point1.GetY())? 1 : -1;
	auto color = this->GetForeground()->GetValue();

	if (dy <= dx)
	{
		int d  = (dy << 1) - dx;

		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;

		int x = _Point1.GetX() + sx;
		int y = _Point1.GetY();

		this->DrawPoint(_Point1.GetX(), _Point1.GetY(), color);

		for (T i = 1; i <= dx; i++, x+= sx)
		{
			if (d > 0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;

			this->DrawPoint(x, y, color);
		}

	}
	else
	{
		int d  = (dx << 1) - dy;

		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;

		int x = _Point1.GetX();
		int y = _Point1.GetY() + sy;

		this->DrawPoint(_Point1.GetX(), _Point1.GetY(), color);

		for (T i = 1; i <= dy; i++, y += sy)
		{
			if (d > 0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;

			this->DrawPoint(x, y, color);
		}
	}
}

template <class T, class TCanvas>
Line<T, TCanvas>::~Line()
{

}

}}
