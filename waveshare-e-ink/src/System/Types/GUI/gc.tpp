// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com

#include "gc.h"
#include "line.h"
#include "circle.h"
#include "Primitives/Include/shapePoint.h"
#include "rectangle.h"
#include "asciiChar.h"

namespace GUI {

using GUI::Primitives::Line;
using GUI::Primitives::Circle;
using GUI::Primitives::Rectangle;
using GUI::Primitives::AsciiChar;

template <class T, class TCanvas>
GC<T, TCanvas>::GC(uint32_t width, uint32_t height)
  : ShapeColor(), Size<uint32_t>(width,height),
	DotPixel<T>(),DotStyle<T>(), LineStyle<T>(),
	ShapeFill(), _Font(NULL), _Canvas(NULL)
{

}

template <class T, class TCanvas>
void GC<T, TCanvas>::Init()
{
	_Canvas = CreateCanvas();
	_Canvas->SetWidth(this->GetWidth());
	_Canvas->SetHeight(this->GetHeight());
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawPoint(T x, T y)
{
	DrawPoint(x, y, this, this->GetDotPixel(), this->GetDotStyle());
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawPoint(T x, T y, ShapeColor* color, T dotPixel, T dotStyle)
{
	GUI::Primitives::ShapePoint<T, TCanvas> point(this, x, y);
	point.SetColor(color);
	point.SetDotPixel(dotPixel);
	point.SetDotStyle(dotStyle);
	point.Draw();
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawLine (T x1, T y1, T x2, T y2)
{
	DrawLine(x1, y1, x2, y2, this, this->GetDotPixel(), this->GetLineStyle());
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawLine (T x1, T y1, T x2, T y2, ShapeColor* color,uint32_t width, uint32_t style)
{
	Line<T, TCanvas> line(this, x1, y1, x2, y2);
	line.SetColor(color);
	line.SetWidth(width);
	line.SetLineStyle(style);
	line.Draw();
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawRectangle(T x1, T y1, T x2, T y2)
{
	DrawRectangle(x1, y1, x2, y2, this, this->GetDotPixel(), this->GetIsDrawFill());
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawRectangle(T x1, T y1, T x2, T y2,ShapeColor* color,uint32_t width,uint32_t drawFill)
{
	Rectangle<T, TCanvas> rect(this, x1, y1, x2, y2);
	rect.SetColor(color);
	rect.SetWidth(width);
	rect.SetIsDrawFill(drawFill);
	rect.Draw();
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawCircle(T x, T y, T radius)
{
	DrawCircle(x, y, radius, this, this->GetDotPixel(), this->GetIsDrawFill());
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawCircle(T x, T y, T radius, ShapeColor* color,uint32_t width, uint32_t drawFill)
{
	Circle<T, TCanvas> circle(this, x, y, radius);
	circle.SetColor(color);
	circle.SetWidth(width);
	circle.SetIsDrawFill(drawFill);
	circle.Draw();
}

template <class T, class TCanvas>
void  GC<T, TCanvas>::DrawChar(Font* font, T x, T y, char asciiChar)
{
	AsciiChar<T,TCanvas> ch(this, x, y, asciiChar, font);

	ch.Draw();
}

template <class T, class TCanvas>
void GC<T, TCanvas>::DrawString(Font* font, T x, T y, string s)
{
	char ch;
	Point<T> p(x,y);
	int length = s.length();

	for (int i = 0; i < length; i++)
	{
		ch = s[i];
    	if (ch == '\0') break;

    	DrawChar(font, p.GetX(), p.GetY(), ch);
		p.AddX(font->GetWidth());
	}
}

template <class T, class TCanvas>
TCanvas* GC<T, TCanvas>::GetCanvas() const
{
	return _Canvas;
}

template <class T, class TCanvas>
GC<T, TCanvas>::~GC()
{
	if (_Canvas != NULL)
		delete _Canvas;
}

}
