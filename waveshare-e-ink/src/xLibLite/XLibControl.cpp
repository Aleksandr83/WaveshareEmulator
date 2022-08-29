// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibControl.h"

namespace XLib {

using XLib::XLibBaseWindow;

XLibControl::XLibControl(XLibDisplay* xlibDisplay, ulong* controlId)
	: XLibBaseWindow(xlibDisplay, controlId)
{

}

XLibControl::~XLibControl()
{

}

} /* namespace XLib */
