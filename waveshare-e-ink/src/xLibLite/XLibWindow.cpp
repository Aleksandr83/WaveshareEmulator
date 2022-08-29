// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibWindow.h"
#include <locale>
#include <codecvt>
#include <string>

namespace XLib {

XLibWindow::XLibWindow(XLibDisplay* xlibDisplay, ulong* windowId)
	:XLibBaseWindow(xlibDisplay,windowId), _XLibDisplay(xlibDisplay),_WindowId(*windowId)
{
	_XLibGC = make_shared<XLibGC>(xlibDisplay, windowId);
}

char* XLibWindow::GetHeader()
{
	unsigned char* result;
	auto window   = GetCoreWindow(true);
	auto property = _XLibDisplay->GetProperty((char*)XLibWindow::__XLIB_PROPERTY_NAME_UTF8_STRING);

	_XLibDisplay->GetWindowProperty(
		window,
		(char*)XLibWindow::__XLIB_PROPERTY_NAME_GET_WIN_NAME,
		property,
		&result
		);

	return reinterpret_cast<char*>(result);
}

void XLibWindow::OnClose()
{

}

XLibWindow::~XLibWindow()
{
}

} /* namespace XLib */
