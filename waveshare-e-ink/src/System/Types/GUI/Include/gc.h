// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_GC_H_
#define SRC_SYSTEM_TYPES_GUI_GC_H_

#include "size.h"
#include "font.h"
#include "dotPixel.h"
#include "dotStyle.h"
#include "shapeColor.h"
#include "shapeFill.h"
#include "lineStyle.h"
#include "PreCompiller.h"

#pragma once


namespace GUI {

using GUI::ShapeColor;
using GUI::Font;

template <class T, class TCanvas>
class GC :
	public ShapeColor, Size<uint32_t>,
	public DotPixel<T>, public DotStyle<T>, public LineStyle<T>, public ShapeFill
{
public:
	enum class TRotate
	{
		d0   = 0,
		d90  = 90,
		d180 = 180,
		d270 = 270
	};

	enum class TMirror
	{
		Default    = 0,
		Horizontal = 1,
		Vertical   = 2,
		Origin     = 3
	};


private:
	Font*    _Font;

	TCanvas* _Canvas;

public:
	GC(uint32_t width, uint32_t height);
	virtual ~GC();

	virtual void Init();

	virtual void Clear() 										   = 0;

	virtual void DrawPoint(T x, T y);
	virtual void DrawPoint(T x, T y, ShapeColor* color, T dotPixel, T dotStyle);
	virtual void DrawLine(T x1, T y1, T x2, T y2);
	virtual void DrawLine(T x1, T y1, T x2, T y2, ShapeColor* color,uint32_t width, uint32_t style);
	virtual void DrawRectangle(T x1, T y1, T x2, T y2);
	virtual void DrawRectangle(T x1, T y1, T x2, T y2,ShapeColor* color,uint32_t width,uint32_t drawFill);
	virtual void DrawCircle(T x, T y, T radius);
	virtual void DrawCircle(T x, T y, T radius, ShapeColor* color,uint32_t width, uint32_t drawFill);
	virtual void DrawChar(Font* font, T x, T y, char asciiChar);
	virtual void DrawString(Font* font, T x, T y, string s);

	virtual TCanvas* GetCanvas() const;

protected:
	virtual TCanvas* CreateCanvas() = 0;

};


}

#include "../gc.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_GC_H_ */
