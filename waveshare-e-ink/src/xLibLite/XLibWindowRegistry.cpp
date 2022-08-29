// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "XLibWindowRegistry.h"

namespace XLib {

XLibWindowRegistry::XLibWindowRegistry()
	:_Items()
{

}

void XLibWindowRegistry::Registred(shared_ptr<XLibWindow> window)
{
	auto result = Find(window->GetWindowId());
	if (result != NULL) return;
	_Items.push_back(window);
}

shared_ptr<XLibWindow> XLibWindowRegistry::Find(Window windowId)
{
	list<shared_ptr<XLibWindow>>::iterator it;
	for (it = _Items.begin(); it != _Items.end(); it++)
	{
		auto item = static_cast<shared_ptr<XLibWindow>>(*it);
		if (item->GetWindowId() == windowId)
			return item;
	}
	return NULL;
}

XLibWindowRegistry::~XLibWindowRegistry()
{
	_Items.clear();
}

} /* namespace XLib */
