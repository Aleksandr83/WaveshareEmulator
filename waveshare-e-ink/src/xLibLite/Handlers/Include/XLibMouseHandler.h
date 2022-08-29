// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_XLIBLITE_XLIBMOUSEHANDLER_H_
#define SRC_XLIBLITE_XLIBMOUSEHANDLER_H_

namespace XLib {
namespace Handlers {

class XLibMouseHandler {
public:
	XLibMouseHandler();
	virtual ~XLibMouseHandler();

protected:
	virtual void OnMouseLeftButtonUp();
	virtual void OnMouseLeftButtonDown();
	virtual void OnMouseLeftButtonClick();
	virtual void OnMouseLeftButtonDoubleClick();
	virtual void OnMouseRightButtonUp();
	virtual void OnMouseRightButtonDown();
	virtual void OnMouseRightButtonClick();
	virtual void OnMouseRightButtonDoubleClick();
	virtual void OnMouseMiddleButtonUp();
	virtual void OnMouseMiddleButtonDown();
	virtual void OnMouseMiddleButtonClick();
	virtual void OnMouseMiddleButtonDoubleClick();
};

}}

#endif /* SRC_XLIBLITE_XLIBMOUSEHANDLER_H_ */
