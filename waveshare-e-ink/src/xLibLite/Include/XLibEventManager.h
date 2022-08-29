// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBEVENTMANAGER_H_
#define SRC_XLIBEVENTMANAGER_H_

#include "PreCompiller.h"

#include "XLibWindow.h"

#pragma once

namespace XLib {

using XLib::XLibWindow;

class XLibEventManager {

public:
	XLibEventManager();
	virtual ~XLibEventManager();

	static void InitEventListener();
	static void Listen(XLibDisplay* xlibDisplay);

};

} /* namespace XLib */

#endif /* SRC_XLIBEVENTMANAGER_H_ */
