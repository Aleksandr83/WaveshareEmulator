// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "shapeFill.h"

namespace GUI {


ShapeFill::ShapeFill()
  :_IsDrawFill(false)
{

}

bool ShapeFill::GetIsDrawFill() const
{
	return _IsDrawFill;
}

void ShapeFill::SetIsDrawFill(bool isDrawFill)
{
	_IsDrawFill =  isDrawFill;
}

ShapeFill::~ShapeFill()
{

}

}
