// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_PRIMITIVES_POINT_H_
#define SRC_SYSTEM_TYPES_GUI_PRIMITIVES_POINT_H_

#include "shape.h"
#include "dotPixel.h"
#include "dotStyle.h"

#pragma once


namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
class ShapePoint :  public GUI::Shape<T, TCanvas>, public GUI::DotPixel<T>,
					public GUI::DotStyle<T>
{
private:
	Point<T> _Coordinates;

public:
	ShapePoint(GC<T, TCanvas>* gc,T x, T y);
	virtual ~ShapePoint();

protected:
	virtual void DrawBorder() override;
	virtual void DrawFill()   override;
	virtual void DrawDotStyleFillAround();

	virtual void SetPixel(T x, T y);

private:
	virtual bool GetIsDrawFill() const          override { return false; }
	virtual void SetIsDrawFill(bool isDrawFill) override { }

};

}}

#include "../shapePoint.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_PRIMITIVES_POINT_H_ */
