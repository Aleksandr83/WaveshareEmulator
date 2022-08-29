// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBDISPLAY_H_
#define SRC_XLIBDISPLAY_H_

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

#include "PreCompiller.h"
#include "XLibWindowCreator.h"
#include "XLibWindow.h"
#include "XLibWindowRegistry.h"

#pragma once

namespace XLib {

class XLibWindow;
class XLibDisplay;
class XLibWindowCreator;
class XLibWindowRegistry;
class XLibBaseWindow;

class XLibDisplay {
private:
	const int 	__ERROR_INT_VALUE = -1;
	const char* __XLIB_PROPERTY_NAME_GET_LIST = "_NET_CLIENT_LIST";

	static const uint32_t __DEFAULT_WINDOW_WIDTH  = 1000;
	static const uint32_t __DEFAULT_WINDOW_HEIGHT = 600;

public:
	typedef  _XGC GC;

private:
	Display* _Display;
	ulong    _CountWindows;
	Window*  _Windows;
	ulong    _Screen;
	GC*      _GC;

	shared_ptr<XLibWindowCreator>  _WindowCreator;
	shared_ptr<XLibWindowRegistry> _WindowRegistry;

public:
	XLibDisplay();
	virtual ~XLibDisplay();

	virtual ulong GetCountWindows();

	virtual void  Init();
	virtual void  Update();

	virtual bool  IsOpenDisplay();

	virtual void  OpenDisplay();
	virtual void  CloseDisplay();

	virtual void  GetWindowSize(XLibBaseWindow* window, uint& width, uint& height, uint& borderWidth);

	virtual shared_ptr<XLibWindow> GetWindowByIndex(ulong index);

	template <class TWindow>
	shared_ptr<TWindow> CreateSimpleWindow(
				uint32_t width  = XLibDisplay::__DEFAULT_WINDOW_WIDTH,
				uint32_t height = XLibDisplay::__DEFAULT_WINDOW_HEIGHT
				);
	template <class TWindow>
	shared_ptr<TWindow> CreateSimpleWindow(
			int32_t x, int32_t y, uint32_t width, uint32_t height);

	template <class TWindow>
	shared_ptr<TWindow> CreateSimpleWindow(
			ulong parentId, int32_t x, int32_t y, uint32_t width, uint32_t height);

protected:
	GC*		 GetGC();
	Display* GetDisplay();
	shared_ptr<XLibWindowRegistry> GetWindowRegistry();

	ulong 	 GetConnectionNumber();
	ulong 	 GetProtocolVersion();
	ulong 	 GetProtocolRevision();
	ulong 	 GetScreenCount();
	ulong    GetScreen();
	ulong 	 GetDefaultScreen();
	ulong 	 GetRootWindow();
	ulong 	 GetDefaultRootWindow();

private:
	ulong    SetScreen(ulong screen);
	Window*  GetAllWindows();
	ulong    SearchWindowIndex(Window* window);

	Atom     GetProperty(char* propertyName);
	ulong    GetWindowProperty(char* propertyName, Atom reqType,unsigned char** result);
	ulong    GetWindowProperty(Window win,char* propertyName, Atom reqType,unsigned char** result);

	void UpdateListAllWindows();

	friend class XLibGC;
	friend class XLibBaseWindow;
	friend class XLibControl;
	friend class XLibWindow;
	friend class XLibWindowCreator;
	friend class XLibEventManager;
};

class XLibWindowCreator {
private:
	XLibDisplay* _XLibDisplay;

public:
	XLibWindowCreator(XLibDisplay* display);
	virtual ~XLibWindowCreator();

	template <class TWindow>
	shared_ptr<TWindow> CreateSimpleWindow(uint32_t width, uint32_t height);

	template <class TWindow>
	shared_ptr<TWindow> CreateSimpleWindow(int32_t x, int32_t y, uint32_t width, uint32_t height);

	template <class TWindow>
	shared_ptr<TWindow> CreateSimpleWindow(ulong  parentId,int32_t x, int32_t y, uint32_t width, uint32_t height);
};

} /* namespace XLib */

#include "../XLibDisplay.tpp"
#include "../XLibWindowCreator.tpp"

#endif /* SRC_XLIBDISPLAY_H_ */
