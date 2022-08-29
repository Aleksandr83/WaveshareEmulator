// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibDisplay.h"
#include <Xlib.h>

namespace XLib {

XLibDisplay::XLibDisplay()
	:_Display(NULL), _CountWindows(0), _Windows(NULL), _Screen(0), _GC(NULL)
{
}

void XLibDisplay::Init()
{
	OpenDisplay();
	if (!IsOpenDisplay()) return;
	SetScreen(GetDefaultScreen());
	_WindowCreator  = make_shared<XLibWindowCreator>(this);
	_WindowRegistry = make_shared<XLibWindowRegistry>();
}

bool XLibDisplay::IsOpenDisplay()
{
	return (_Display != NULL);
}

Display* XLibDisplay::GetDisplay()
{
	return _Display;
}

shared_ptr<XLibWindowRegistry> XLibDisplay::GetWindowRegistry()
{
	return _WindowRegistry;
}

Window* XLibDisplay::GetAllWindows()
{
	return _Windows;
}

ulong XLibDisplay::GetCountWindows()
{
	return  _CountWindows;
}

void  XLibDisplay::GetWindowSize(XLibBaseWindow* window, uint& width, uint& height, uint& borderWidth)
{
	Window root;
	int    x, y;

	unsigned int depth;

	auto win = (Window)window->GetWindowId();

	int status = XGetGeometry(
			_Display,
			win,
			&root,
			&x,
			&y,
			&width,
			&height,
			&borderWidth,
			&depth
	);

}

Atom  XLibDisplay::GetProperty(char* propertyName)
{
	return XInternAtom(_Display, propertyName, False);
}

ulong XLibDisplay::GetConnectionNumber()
{
	if (!IsOpenDisplay())
		return XLibDisplay::__ERROR_INT_VALUE;
	return ConnectionNumber(_Display);
}

ulong XLibDisplay::GetProtocolVersion()
{
	if (!IsOpenDisplay())
		return XLibDisplay::__ERROR_INT_VALUE;
	return ProtocolVersion(_Display);
}

ulong XLibDisplay::GetProtocolRevision()
{
	if (!IsOpenDisplay())
		return XLibDisplay::__ERROR_INT_VALUE;
	return ProtocolRevision(_Display);
}

ulong XLibDisplay::GetScreenCount()
{
	if (!IsOpenDisplay())
		return XLibDisplay::__ERROR_INT_VALUE;
	return ScreenCount(_Display);
}

ulong XLibDisplay::GetScreen()
{
	return _Screen;
}

XLibDisplay::GC* XLibDisplay::GetGC()
{
	return _GC;
}

ulong XLibDisplay::SetScreen(ulong screen)
{
	_Screen = screen;
	_GC     = DefaultGC(_Display, _Screen);
	return _Screen;
}

ulong XLibDisplay::GetDefaultScreen()
{
	if (!IsOpenDisplay())
		return XLibDisplay::__ERROR_INT_VALUE;
	return DefaultScreen(_Display);
}

ulong XLibDisplay::GetRootWindow()
{
	return RootWindow(_Display, _Screen);
}

ulong XLibDisplay::GetDefaultRootWindow()
{
	return DefaultRootWindow(_Display);
}

void XLibDisplay::Update()
{
	OpenDisplay();
	if (!IsOpenDisplay()) return;
	UpdateListAllWindows();
}

void XLibDisplay::OpenDisplay()
{
	if (IsOpenDisplay()) return;
	_Display = XOpenDisplay(NULL);
}

void XLibDisplay::CloseDisplay()
{
	if (!IsOpenDisplay()) return;
	XCloseDisplay(_Display);
	_Display = NULL;
}

shared_ptr<XLibWindow> XLibDisplay::GetWindowByIndex(ulong index)
{
	auto result = _WindowRegistry->Find(index);
	return (result != NULL)? result : make_shared<XLibWindow>(this,&index);
}

ulong XLibDisplay::GetWindowProperty(char* propertyName, Atom reqType,unsigned char** result)
{
	return GetWindowProperty(GetDefaultRootWindow(),propertyName,reqType, result);
}

ulong XLibDisplay::GetWindowProperty(Window win, char* propertyName, Atom reqType,unsigned char** result)
{
	int   format;
	ulong count = 0L;
	Atom  actualType;
	ulong bytesAfter;

	auto  property = GetProperty((char*)propertyName);

	int status = XGetWindowProperty(
		_Display,
		win,
		property,
		0L,
		~0L,
		False,
		reqType,
		&actualType,
		&format,
		&count,
		&bytesAfter,
		result
		);

	if (status != Success) count = 0;
	return count;
}

ulong XLibDisplay::SearchWindowIndex(Window* window)
{
	UpdateListAllWindows();
	ulong index = _CountWindows;
	while (index > 0)
	{
		if (_Windows[index - 1] == *window)
		{
			return --index;
		}
		index--;
	}
	return index;
}

void XLibDisplay::UpdateListAllWindows()
{
	unsigned char* list;
	_CountWindows = GetWindowProperty((char*)XLibDisplay::__XLIB_PROPERTY_NAME_GET_LIST,XA_WINDOW,&list);
	_Windows      = reinterpret_cast<Window*>(list);
}

XLibDisplay::~XLibDisplay()
{
	CloseDisplay();
}

} /* namespace XLib */
