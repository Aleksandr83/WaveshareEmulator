// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBLITE_XLIBDISPLAY_TPP_
#define SRC_XLIBLITE_XLIBDISPLAY_TPP_

#include "XLibDisplay.h"
#include "XLibWindowCreator.h"

#pragma once

namespace XLib {

template <class TWindow>
shared_ptr<TWindow> XLibDisplay::CreateSimpleWindow(uint32_t width,uint32_t height)
{
	return _WindowCreator->CreateSimpleWindow<TWindow>(width, height);
}

template <class TWindow>
shared_ptr<TWindow> XLibDisplay::CreateSimpleWindow(
		int32_t x, int32_t y, uint32_t width, uint32_t height)
{
	return _WindowCreator->CreateSimpleWindow<TWindow>(x, y, width, height);
}

template <class TWindow>
shared_ptr<TWindow> XLibDisplay::CreateSimpleWindow(
		ulong parentId, int32_t x, int32_t y, uint32_t width, uint32_t height)
{
	return _WindowCreator->CreateSimpleWindow<TWindow>(parentId, x, y, width, height);;
}

} // end namespace XLib

#endif /* SRC_XLIBLITE_XLIBDISPLAY_TPP_ */
