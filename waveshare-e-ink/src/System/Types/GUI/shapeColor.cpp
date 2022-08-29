// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "shapeColor.h"

namespace GUI {

ShapeColor::ShapeColor()
  //:_Color(0)
{

}

//uint32_t ShapeColor::GetColor() const
//{
//	return _Color;
//}
//
//void ShapeColor::SetColor(uint32_t color)
//{
//	_Color = color;
//}

Color<uint32_t>* ShapeColor::GetBackground()
{
	return &_Background;
}

Color<uint32_t>* ShapeColor::GetForeground()
{
	return &_Foreground;
}

void ShapeColor::SetColor(ShapeColor* color)
{
	_Background.SetValue(color->GetBackground()->GetValue());
	_Foreground.SetValue(color->GetForeground()->GetValue());
}

ShapeColor::~ShapeColor()
{

}

} /* namespace GUI */
