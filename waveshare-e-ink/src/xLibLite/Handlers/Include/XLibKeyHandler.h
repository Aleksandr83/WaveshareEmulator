// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBLITE_XLIBKEYHANDLER_H_
#define SRC_XLIBLITE_XLIBKEYHANDLER_H_

namespace XLib {
namespace Handlers {

class XLibKeyHandler {
public:
	XLibKeyHandler();
	virtual ~XLibKeyHandler();

protected:
	virtual void OnKeyUp();
	virtual void OnKeyDown();

};

}}

#endif /* SRC_XLIBLITE_XLIBKEYHANDLER_H_ */
