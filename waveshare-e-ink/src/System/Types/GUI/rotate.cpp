// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "rotate.h"

namespace GUI {

Rotate::Rotate()
  :_Angle(0)
{

}

uint16_t Rotate::GetRotateAngle() const
{
	return _Angle;
}

void Rotate::SetRotateAngle(uint16_t angle)
{
	_Angle = angle;
}

Rotate::~Rotate()
{

}

}
