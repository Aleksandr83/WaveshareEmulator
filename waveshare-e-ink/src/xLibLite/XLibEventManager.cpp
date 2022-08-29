// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibEventManager.h"

namespace XLib {

XLibEventManager::XLibEventManager() {

}

void XLibEventManager::InitEventListener()
{

}

void XLibEventManager::Listen(XLibDisplay* xlibDisplay)
{
	XEvent event;
	InitEventListener();

	auto registry = xlibDisplay->GetWindowRegistry();
	auto wm_delete_window = xlibDisplay->GetProperty((char*)"WM_DELETE_WINDOW");

	for(;;)
	{
		XNextEvent(xlibDisplay->GetDisplay(), &event);

		auto windowId = event.xmapping.window;
		auto window   = xlibDisplay->GetWindowByIndex(windowId);

		if (event.type == ClientMessage)
		{
			if ((Atom)event.xclient.data.l[0] == wm_delete_window)
			{
				if (window != NULL) window->OnClose();
				break;
			}
		}

		if (window == NULL) continue;

		if (event.type == Expose)
		{
			window->OnPaint(window->GetXlibGC());
			XFlush(xlibDisplay->GetDisplay());
			continue;
		}
//		if (event.type == KeyPress)
//		{
//			// event.xkey.keycode
//			window->OnKeyUp();
//			continue;
//		}
//		if (event.type == KeyRelease)
//		{
//			//  event.xkey.keycode
//			window->OnKeyDown();
//			continue;
//		}
//		if (event.type == ButtonPress)
//		{
//			//window->OnMouseUp();
//			continue;
//		}
//		if (event.type == ButtonRelease)
//		{
//			//window->OnMouseDown();
//			continue;
//		}

	}
}

XLibEventManager::~XLibEventManager() {

}

} /* namespace XLib */
