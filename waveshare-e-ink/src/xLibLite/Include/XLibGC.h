// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBLITE_XLIBGC_H_
#define SRC_XLIBLITE_XLIBGC_H_

#include "XLibDisplay.h"

#pragma once

namespace XLib {

class XLibDisplay;

class XLibGC {
public:
	typedef  _XGC GC;

private:
	GC*   _GC;
	ulong _WindowId;

	XLib::XLibDisplay* _XLibDisplay;

public:
	XLibGC(XLib::XLibDisplay* display, ulong* windowId);
	virtual ~XLibGC();

	void SetForeground(int red,int green, int blue);
	void SetBackground(int red,int green, int blue);

	void Point(double x, double y);
	void Line(double x1, double y1,double x2, double y2);
	void Arc(double x, double y, double width, double height,double angle);
	void FillArc(double x, double y, double width, double height,double angle);
	void Rectangle(double x, double y, double width, double height);
	void FillRectangle(double x, double y, double width, double height);
	void String(double x, double y, char* str);

};

} /* namespace XLib */

#endif /* SRC_XLIBLITE_XLIBGC_H_ */
