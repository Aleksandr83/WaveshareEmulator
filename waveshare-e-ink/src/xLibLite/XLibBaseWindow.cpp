// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibBaseWindow.h"
#include "XLibWindow.h"

namespace XLib {

using XLib::Handlers::XLibKeyHandler;
using XLib::Handlers::XLibMouseHandler;

XLibBaseWindow::XLibBaseWindow(XLibDisplay* xlibDisplay, ulong* windowId)
	:XLibKeyHandler(), XLibMouseHandler(),
	 _XLibDisplay(xlibDisplay),_WindowId(*windowId), _Type(-1)
{

}

void XLibBaseWindow::Init()
{
	InitXLibGC();
}

void XLibBaseWindow::InitXLibGC()
{
	_XLibGC = make_shared<XLibGC>(_XLibDisplay, &_WindowId);
}

int XLibBaseWindow::GetType()const
{
	return _Type;
}

void XLibBaseWindow::SetType(int type)
{
	_Type = type;
}

ulong XLibBaseWindow::GetWindowId()const
{
	return _WindowId;
}

shared_ptr<XLibGC> XLibBaseWindow::GetXlibGC()
{
	return _XLibGC;
}

XLibDisplay* XLibBaseWindow::GetXLibDisplay()
{
	return _XLibDisplay;
}

Window XLibBaseWindow::GetCoreWindow(bool isUpdateWindowList)
{
	if (isUpdateWindowList) _XLibDisplay->Update();
	auto   windows = _XLibDisplay->GetAllWindows();
	return windows[_WindowId];
}

void XLibBaseWindow::Show()
{
	XMapWindow(_XLibDisplay->GetDisplay(),_WindowId);
}

void XLibBaseWindow::GetWindowSize(uint& width, uint& height, uint& borderWidth)
{
	_XLibDisplay->GetWindowSize(this, width, height, borderWidth);
}

void XLibBaseWindow::OnPaint(shared_ptr<XLibGC> xlibGC)
{

}

XLibBaseWindow::~XLibBaseWindow()
{

}

} /* namespace XLib */
