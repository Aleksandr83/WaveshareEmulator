// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBWINDOW_H_
#define SRC_XLIBWINDOW_H_

#include "PreCompiller.h"
#include "XLibGC.h"
#include "XLibDisplay.h"
#include "XLibBaseWindow.h"
#include "XLibKeyHandler.h"
#include "XLibMouseHandler.h"

#pragma once

namespace XLib {

class XLibGC;
class XLibDisplay;

using XLib::Handlers::XLibKeyHandler;
using XLib::Handlers::XLibMouseHandler;

class XLibBaseWindow :
		public virtual XLibKeyHandler,
		public virtual XLibMouseHandler
{
private:
	XLibDisplay* 	   _XLibDisplay;
	ulong 			   _WindowId;
	shared_ptr<XLibGC> _XLibGC;
	int 			   _Type;

public:
	XLibBaseWindow(XLibDisplay* xlibDisplay, ulong* windowId);
	virtual ~XLibBaseWindow();

	int   GetType()const;
	ulong GetWindowId()const;

	virtual void Init();
	virtual void Show();

protected:
	virtual void InitXLibGC();
	virtual void SetType(int type);

	virtual shared_ptr<XLibGC> GetXlibGC();
	virtual Window			   GetCoreWindow(bool isUpdateWindowList = false);
	virtual XLibDisplay* 	   GetXLibDisplay();
	virtual void               GetWindowSize(uint& width, uint& height, uint& borderWidth);

	virtual void OnPaint(shared_ptr<XLibGC> xlibGC);

};

class XLibControl : public XLibBaseWindow
{
public:
	XLibControl(XLibDisplay* xlibDisplay, ulong* controlId);
	virtual ~XLibControl();

};

class XLibWindow : public XLibBaseWindow
{
private:
	const char* __XLIB_PROPERTY_NAME_GET_WIN_NAME = "_NET_WM_NAME";
	const char* __XLIB_PROPERTY_NAME_UTF8_STRING  = "UTF8_STRING";

private:
	XLib::XLibDisplay* _XLibDisplay;
	ulong 			   _WindowId;
	shared_ptr<XLibGC> _XLibGC;

public:
	XLibWindow(XLibDisplay* xlibDisplay, ulong* windowId);
	virtual ~XLibWindow();

	char* GetHeader();

protected:
	virtual void OnClose();

private:

	friend class XLibEventManager;
};

} /* namespace XLib */

#endif /* SRC_XLIBWINDOW_H_ */
