// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "shape.h"

namespace GUI {

template <class T, class TCanvas>
Shape<T, TCanvas>::Shape(GC<T, TCanvas>* gc)
  :ShapeColor(), ShapeFill(), Size<T>(1,0), _GC(gc)
{

}

template <class T, class TCanvas>
void Shape<T, TCanvas>::Draw()
{
	DrawBorder();
	DrawFill();
}

template <class T, class TCanvas>
GC<T, TCanvas>* Shape<T, TCanvas>::GetGC() const
{
	return _GC;
}

template <class T, class TCanvas>
void Shape<T, TCanvas>::DrawPoint(T x, T y, uint32_t color)
{
	ShapeColor pointColor;
	auto* gc   = this->GetGC();
	auto width = Size<T>::GetWidth();
	pointColor = (ShapeColor)*gc;
	pointColor.GetForeground()->SetValue(color);
	gc->DrawPoint(x, y, &pointColor, (width == 0)? 1 : width, gc->GetDotStyle());
}

template <class T, class TCanvas>
Shape<T, TCanvas>::~Shape()
{

}

} /* namespace GUI */
