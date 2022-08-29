// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "font.h"

namespace GUI {

Font::Font()
  :Size(), Length<uint32_t>(), _Table(NULL)
{

}

uint8_t* Font::GetTablePtr() const
{
	return _Table;
}

void Font::SetWidth (uint8_t value)
{
	Size::SetWidth(value);
}

void Font::SetHeight(uint8_t value)
{
	Size::SetHeight(value);
}

void Font::SetFontName(string value)
{
	_FontName = value;
}

void Font::SetTablePtr(uint8_t* value)
{
	_Table = value;
}

uint8_t  Font::GetWidthInBytes()
{
	auto width = this->GetWidth();
	return (width / 8 + (width % 8 ? 1 : 0));
}

Font::~Font()
{

}

} /* namespace XLib */
