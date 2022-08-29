// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBLITE_XLIBWINDOWCREATOR_TPP_
#define SRC_XLIBLITE_XLIBWINDOWCREATOR_TPP_

#include "XLibDisplay.h"

#pragma once

namespace XLib {

template <class TWindow>
shared_ptr<TWindow> XLibWindowCreator::CreateSimpleWindow(uint32_t width, uint32_t height)
{
	return CreateSimpleWindow<TWindow>(0, 0, width, height);
}

template <class TWindow>
shared_ptr<TWindow> XLibWindowCreator::CreateSimpleWindow(int32_t x, int32_t y, uint32_t width, uint32_t height)
{
	return CreateSimpleWindow<TWindow>(_XLibDisplay->GetRootWindow(),0, 0, width, height);
}

template <class TWindow>
shared_ptr<TWindow> XLibWindowCreator::CreateSimpleWindow(ulong  parentId,int32_t x, int32_t y, uint32_t width, uint32_t height)
{
	auto windowId = XCreateSimpleWindow(
		_XLibDisplay->GetDisplay(),
		parentId,
		x,
		y,
		width,
		height,
		1,
		BlackPixel(_XLibDisplay->GetDisplay(), _XLibDisplay->GetScreen()),
		WhitePixel(_XLibDisplay->GetDisplay(), _XLibDisplay->GetScreen())
		);

		auto window   = make_shared<TWindow>(_XLibDisplay, &windowId);
		auto registry = _XLibDisplay->GetWindowRegistry();

		window->Init();
		registry->Registred(dynamic_pointer_cast<XLibWindow>(window));

		XSelectInput(_XLibDisplay->GetDisplay(), window->GetWindowId() , ExposureMask | KeyPressMask );

		auto wmDeleteMessage = _XLibDisplay->GetProperty((char*)"WM_DELETE_WINDOW");
		XSetWMProtocols(_XLibDisplay->GetDisplay(), window->GetWindowId(), &wmDeleteMessage, 1);

		return window;
}

} // end namespace XLib

#endif
