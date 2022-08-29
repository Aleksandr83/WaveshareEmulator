// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_CIRCLE_H_
#define SRC_SYSTEM_TYPES_GUI_CIRCLE_H_


#include "shape.h"


#pragma once


namespace GUI {
namespace Primitives {

using GUI::ShapeFill;

template <class T, class TCanvas>
class Circle : public Shape<T, TCanvas>
{
private:
	Point<T> _Center;
	T		 _Radius;

public:
	Circle(GC<T, TCanvas>* gc,T x, T y, T radius);
	virtual ~Circle();

protected:
	virtual void DrawBorder() override;
	virtual void DrawFill()   override;
	virtual bool IsPointBorderColor(T x, T y);
	virtual void DrawCirclePoints(T x, T y);

private:
	inline void DrawCircle(T radius);

};

}}

#include "../circle.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_CIRCLE_H_ */
