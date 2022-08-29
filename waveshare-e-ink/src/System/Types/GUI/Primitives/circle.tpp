// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "circle.h"

namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
Circle<T, TCanvas>::Circle(GC<T, TCanvas>* gc,T x, T y, T radius)
  :Shape<T, TCanvas>(gc), _Center(x, y), _Radius(radius)
{

}

template <class T, class TCanvas>
void Circle<T, TCanvas>::DrawBorder()
{
	DrawCircle(_Radius);
}

template <class T, class TCanvas>
void Circle<T, TCanvas>::DrawFill()
{
	if (!this->GetIsDrawFill()) return;
	return; // temp

	int r = _Radius;
	int d = r * 2;

	auto color = this->GetBackground()->GetValue();

	Point<T> point;
	point.SetY(_Center.GetY() - r +1);

	for (int i = 0; i < d-1; i++)
	{
		T x = _Center.GetX();

		int borderX = 0;
		for (int j  = 0; j <= r; j++)
		{
			borderX = x-j+1;
			if (IsPointBorderColor(borderX, point.GetY()))
				break;
		}

		int n = (x - borderX) * 2 + 1;

		for (int j = 0; j < n; j++)
		{
			this->DrawPoint(borderX+j, point.GetY(), color);
		}

		point.AddY();
	}
}

template <class T, class TCanvas>
void Circle<T, TCanvas>::DrawCircle(T radius)
{
	T x   = 0;
	T y   = radius;
	int d = 1 - radius;
	int delta1 = 3;
	int delta2 = -2 * radius + 5;
	DrawCirclePoints(x, y);
	while (y > x)
	{
		if (d < 0)
		{
			d += delta1;
			delta1 += 2;
			delta2 += 2;
			x++;
		}
		else
		{
			d += delta2;
			delta1 += 2;
			delta2 += 4;
			x++;
			y--;
		}
		DrawCirclePoints(x, y);
	}
}

template <class T, class TCanvas>
void Circle<T, TCanvas>::DrawCirclePoints(T x, T y)
{
	auto color = this->GetForeground()->GetValue();

	this->DrawPoint(_Center.GetX() + x, _Center.GetY() + y, color);
	this->DrawPoint(_Center.GetX() + y, _Center.GetY() + x, color);
	this->DrawPoint(_Center.GetX() + y, _Center.GetY() - x, color);
	this->DrawPoint(_Center.GetX() + x, _Center.GetY() - y, color);
	this->DrawPoint(_Center.GetX() - x, _Center.GetY() - y, color);
	this->DrawPoint(_Center.GetX() - y, _Center.GetY() - x, color);
	this->DrawPoint(_Center.GetX() - y, _Center.GetY() + x, color);
	this->DrawPoint(_Center.GetX() - x, _Center.GetY() + y, color);
}

template <class T, class TCanvas>
bool Circle<T, TCanvas>::IsPointBorderColor(T x, T y)
{
	auto* canvas = this->GetGC()->GetCanvas();
	return (canvas->GetPixel(x,y) == this->GetForeground()->GetValue());
}

template <class T, class TCanvas>
Circle<T, TCanvas>::~Circle()
{

}

}}
