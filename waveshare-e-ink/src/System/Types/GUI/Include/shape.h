// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_SHAPE_H_
#define SRC_SYSTEM_TYPES_GUI_SHAPE_H_

#include "gc.h"
#include "point.h"
#include "size.h"
#include "shapeColor.h"
#include "shapeFill.h"

#pragma once


namespace GUI {

using GUI::ShapeColor;
using GUI::ShapeFill;

template <class T, class TCanvas>
class Shape : public ShapeColor, public ShapeFill, public Size<T>
{
private:
	GC<T, TCanvas>*  _GC;

public:
	Shape(GC<T, TCanvas>* gc);
	virtual ~Shape();

	virtual void Draw();

protected:
	virtual GC<T, TCanvas>* GetGC() const;

	virtual T    GetHeight() const  override { return 0;}
	virtual void SetHeight(T value) override {};

	virtual void DrawBorder() = 0;
	virtual void DrawFill()   = 0;

	virtual void DrawPoint(T x, T y, uint32_t color);

	//virtual void DrawFill()   = 0;
	//virtual void DrawNormal() = 0;

};

} /* namespace GUI */

#include "../shape.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_SHAPE_H_ */
