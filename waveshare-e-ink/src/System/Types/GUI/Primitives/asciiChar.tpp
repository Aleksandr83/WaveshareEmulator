// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "asciiChar.h"
#include "font8.h"
#include "bits.h"
#include "point.h"


namespace GUI {
namespace Primitives {


using GUI::Point;


template <class T, class TCanvas>
AsciiChar<T, TCanvas>::AsciiChar(GC<T, TCanvas>* gc, T x, T y, char value, Font* font)
  :_GC(gc), _Coordinates(x, y), _Font(font)
{
	_Value.SetValue(value);
}

template <class T, class TCanvas>
void AsciiChar<T, TCanvas>::Draw()
{
	char charValue  = _Value.GetValue();
	if (charValue == '\0') return;

	uint32_t width  = _Font->GetWidth();
	uint32_t height = _Font->GetHeight();

	uint8_t  fontWidth = _Font->GetWidthInBytes();

	uint32_t offset = (charValue - ' ') * height * fontWidth;

	uint8_t *ptr = (_Font->GetTablePtr() + offset);

	auto x = _Coordinates.GetX();
	auto y = _Coordinates.GetY();

	for (uint row = 0; row < height; row++, ptr=ptr + fontWidth)
	{
		for (uint column = 0; column < width; column++)
		{
			auto columnOffset = column / 8;

			if (__IS_SET_BIT(*(ptr + columnOffset), 7 - column % 8))
			{
				_GC->DrawPoint(x + column, y + row);
			}
			else
			{

			}
		}
	}

}

template <class T, class TCanvas>
AsciiChar<T, TCanvas>::~AsciiChar()
{

}

}}
