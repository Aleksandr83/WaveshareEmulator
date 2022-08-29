// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "rectangle.h"

namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
Rectangle<T, TCanvas>::Rectangle(GC<T, TCanvas>* gc, T x1, T y1, T x2, T y2)
  :Shape<T, TCanvas>(gc), _X1(x1), _Y1(y1), _X2(x2), _Y2(y2)
{

}

template <class T, class TCanvas>
void Rectangle<T, TCanvas>::DrawBorder()
{
	auto color = this->GetBackground()->GetValue();

	DrawLine(_X1, _Y1, _X2, _Y1, color);
	DrawLine(_X1, _Y1, _X1, _Y2, color);
	DrawLine(_X2, _Y2, _X2, _Y1, color);
	DrawLine(_X2, _Y2, _X1, _Y2, color);
}

template <class T, class TCanvas>
void Rectangle<T, TCanvas>::DrawFill()
{
	if (!this->GetIsDrawFill()) return;

	auto color = this->GetBackground()->GetValue();

	T y1 = (_Y1 < _Y2)? _Y1 : _Y2;
	T y2 = (_Y1 < _Y2)? _Y2 : _Y1;

	for (T i = y1; i <= y2; i++)
	{
		DrawLine(_X1, i, _X2, i, color);
	}
}

template <class T, class TCanvas>
void Rectangle<T, TCanvas>::DrawLine(T x1, T y1, T x2, T y2, uint32_t color)
{
	auto*   gc = this->GetGC();
	auto width = Size<T>::GetWidth();

	gc->DrawLine(x1, y1, x2, y2,gc, width, gc->GetDotStyle());
}

template <class T, class TCanvas>
Rectangle<T, TCanvas>::~Rectangle()
{

}

}}
