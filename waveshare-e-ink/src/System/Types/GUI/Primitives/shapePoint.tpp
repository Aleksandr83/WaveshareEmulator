// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "shapePoint.h"
#include "point.h"

namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
ShapePoint<T, TCanvas>::ShapePoint(GC<T, TCanvas>* gc,T x, T y)
  :GUI::Shape<T, TCanvas>(gc), GUI::DotPixel<T>(), GUI::DotStyle<T>(),
   _Coordinates(x, y)
{

}

template <class T, class TCanvas>
void ShapePoint<T, TCanvas>::DrawFill()
{

}

template <class T, class TCanvas>
void ShapePoint<T, TCanvas>::DrawBorder()
{
	T xNum , yNum;

	if (this->GetDotStyle() == (int)DotStyle<T>::TDotStyle::FillAround)
	{
		DrawDotStyleFillAround();
		return;
	}

	auto dotPixel = this->GetDotPixel();

	for (xNum = 1; xNum <= dotPixel; xNum++)
	{
		for (yNum = 1; yNum <=  dotPixel; yNum++)
		{
		    SetPixel(_Coordinates.GetX() + xNum - 1, _Coordinates.GetY() + yNum - 1);
		}
	}
}

template <class T, class TCanvas>
void ShapePoint<T, TCanvas>::DrawDotStyleFillAround()
{
	T xNum , yNum;
	auto dotPixel = this->GetDotPixel();

	for (xNum = 0; xNum < 2 * dotPixel - 1; xNum++)
	{
		for (yNum = 0; yNum < 2 * dotPixel - 1; yNum++)
		{
			T x = _Coordinates.GetX() + xNum - dotPixel;
			T y = _Coordinates.GetY() + yNum - dotPixel;

		    if(x < 0 || y < 0) break;

		    SetPixel(x, y);
		}
	}
}

template <class T, class TCanvas>
void ShapePoint<T, TCanvas>::SetPixel(T x, T y)
{
	auto* canvas = this->GetGC()->GetCanvas();
	canvas->SetPixel(x, y, 0);
}

template <class T, class TCanvas>
ShapePoint<T, TCanvas>::~ShapePoint()
{

}

}}
