// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBWINDOWREGISTRY_H_
#define SRC_XLIBWINDOWREGISTRY_H_

#include "PreCompiller.h"
#include "XLibWindow.h"

#pragma once

namespace XLib {

class XLibWindow;

class XLibWindowRegistry {
private:
	list<shared_ptr<XLibWindow>> _Items;

public:
	XLibWindowRegistry();
	virtual ~XLibWindowRegistry();

	void Registred(shared_ptr<XLibWindow> window);

	shared_ptr<XLibWindow>  Find(Window windowId);

};

} /* namespace XLib */

#endif /* SRC_XLIBWINDOWREGISTRY_H_ */
