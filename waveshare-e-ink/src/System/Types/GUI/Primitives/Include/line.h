// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_PRIMITIVES_LINE_H_
#define SRC_SYSTEM_TYPES_GUI_PRIMITIVES_LINE_H_


#include "shape.h"
#include "lineStyle.h"

#pragma once


namespace GUI {
namespace Primitives {

template <class T, class TCanvas>
class Line : public Shape<T, TCanvas>, public LineStyle<T>
{
private:
	Point<T> _Point1;
	Point<T> _Point2;

public:
	Line(GC<T, TCanvas>* gc, T x1, T y1, T x2, T y2);
	virtual ~Line();

protected:
	virtual void DrawBorder() override;
	virtual void DrawFill()   override;

private:
	virtual bool GetIsDrawFill() const          override { return false; }
	virtual void SetIsDrawFill(bool isDrawFill) override { }
};

}}

#include "../line.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_PRIMITIVES_LINE_H_ */
