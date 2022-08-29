// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_RECTANGLE_H_
#define SRC_SYSTEM_TYPES_GUI_RECTANGLE_H_

#include "gc.h"
#include "shape.h"


#pragma once


namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
class Rectangle : public Shape<T, TCanvas>
{
private:
	T _X1;
	T _Y1;
	T _X2;
	T _Y2;

public:
	Rectangle(GC<T, TCanvas>* gc, T x1, T y1, T x2, T y2);
	virtual ~Rectangle();

protected:
	virtual void DrawBorder() override;
	virtual void DrawFill()   override;
	virtual void DrawLine(T x1, T y1, T x2, T y2, uint32_t color);


};

}}

#include "../rectangle.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_RECTANGLE_H_ */
