// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_PRIMITIVES_ASCIICHAR_H_
#define SRC_SYSTEM_TYPES_GUI_PRIMITIVES_ASCIICHAR_H_

#include "PreCompiller.h"
#include "value.h"
#include "point.h"

#pragma once


namespace GUI {
namespace Primitives {

using OS::Types::Generic::Value;
using GUI::Point;

template <class T, class TCanvas>
class AsciiChar
{
private:
	GC<T, TCanvas>*  _GC;

	Value<char> 	_Value;
	Point<T>    	_Coordinates;
	Font*       	_Font;

public:
	AsciiChar(GC<T, TCanvas>* gc, T x, T y, char value, Font* font);
	virtual ~AsciiChar();

	virtual void Draw();

};

}}

#include "../asciiChar.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_PRIMITIVES_ASCIICHAR_H_ */
