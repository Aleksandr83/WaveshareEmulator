// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibGC.h"
#include <cmath>

namespace XLib {

XLibGC::XLibGC(XLib::XLibDisplay* display, ulong* windowId)
	:_GC(display->_GC), _WindowId(*windowId), _XLibDisplay(display)
{

}

void XLibGC::SetForeground(int red,int green, int blue)
{
	auto display = _XLibDisplay->GetDisplay();
	XSetForeground(display, _GC, static_cast<unsigned long>(blue + (green<<8) + (red<<16)));
}

void XLibGC::SetBackground(int red,int green, int blue)
{
	auto display = _XLibDisplay->GetDisplay();
	XSetWindowBackground(display, _WindowId, static_cast<unsigned long>(blue + (green<<8) + (red<<16)));
	XClearArea(display, _WindowId, 0, 0, 0, 0, True);
}

void XLibGC::Point(double x, double y)
{
	auto display = _XLibDisplay->GetDisplay();
	int rectX 	   = static_cast<int>(round(x));
	int rectY 	   = static_cast<int>(round(y));
	XDrawPoint(display , _WindowId, _GC, rectX, rectY);
}

void XLibGC::Line(double x1, double y1,double x2, double y2)
{
	auto display = _XLibDisplay->GetDisplay();
	int lineX1 	 = static_cast<int>(round(x1));
	int lineY1 	 = static_cast<int>(round(y1));
	int lineX2   = static_cast<int>(round(x2));
	int lineY2   = static_cast<int>(round(y2));
	XDrawLine(display , _WindowId, _GC, lineX1, lineY1, lineX2, lineY2);
}

void XLibGC::Arc(double x, double y, double width, double height,double angle)
{
	auto display = _XLibDisplay->GetDisplay();
	int rectX 	   = static_cast<int>(round(x));
	int rectY 	   = static_cast<int>(round(y));
	int rectWidth  = static_cast<int>(round(width));
	int rectHeight = static_cast<int>(round(height));
	XDrawArc(display , _WindowId, _GC, rectX, rectY, rectWidth, rectHeight, 0, angle*64);
}

void XLibGC::FillArc(double x, double y, double width, double height,double angle)
{
	auto display = _XLibDisplay->GetDisplay();
	int rectX 	   = static_cast<int>(round(x));
	int rectY 	   = static_cast<int>(round(y));
	int rectWidth  = static_cast<int>(round(width));
	int rectHeight = static_cast<int>(round(height));
	XFillArc(display , _WindowId, _GC, rectX, rectY, rectWidth, rectHeight, 0, angle*64);
}

void XLibGC::Rectangle(double x, double y, double width, double height)
{
	auto display = _XLibDisplay->GetDisplay();
	int rectX 	   = static_cast<int>(round(x));
	int rectY 	   = static_cast<int>(round(y));
	int rectWidth  = static_cast<int>(round(width));
	int rectHeight = static_cast<int>(round(height));
	XDrawRectangle( display , _WindowId, _GC, rectX, rectY, rectWidth, rectHeight);
}

void XLibGC::FillRectangle(double x, double y, double width, double height)
{
	auto display = _XLibDisplay->GetDisplay();
	int rectX 	   = static_cast<int>(round(x));
	int rectY 	   = static_cast<int>(round(y));
	int rectWidth  = static_cast<int>(round(width));
	int rectHeight = static_cast<int>(round(height));
	XFillRectangle( display , _WindowId, _GC, rectX, rectY, rectWidth, rectHeight);
}

void XLibGC::String(double x, double y, char* str)
{
	auto display = _XLibDisplay->GetDisplay();
	int rectX 	   = static_cast<int>(round(x));
	int rectY 	   = static_cast<int>(round(y));
	XDrawString(display , _WindowId, _GC, rectX, rectY, str, strlen(str));
}

XLibGC::~XLibGC()
{
}

} /* namespace XLib */
