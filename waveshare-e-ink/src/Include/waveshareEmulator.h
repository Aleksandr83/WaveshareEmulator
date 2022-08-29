// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef WAVESHAREEMULATOR_H_
#define WAVESHAREEMULATOR_H_

#include "PreCompiller.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#include "XLibDisplay.h"
#include "XLibEventManager.h"
#include "XLibWindow.h"

#include "dataBuffer.h"
#include "wsEInkGC.h"

#pragma once

using namespace XLib;
using OS::Types::Generic::DataBuffer;
using GUI::Waveshare::EInk::WsEInkGC;

class WaveshareEmulator : public XLibWindow
{
private:
	const uint32_t __WIDTH  = 128;
	const uint32_t __HEIGHT = 296;

	const uint32_t __SCALE  = 3;

	const uint32_t __BUFFER_LENGTH = __WIDTH / 8 * __HEIGHT;

	DataBuffer<uint8_t,uint32_t> _PaintBuffer;
	WsEInkGC* 					 _EGC;

public:
	WaveshareEmulator(XLibDisplay* xlibDisplay, ulong* winIndex);
	virtual ~WaveshareEmulator();

	void Init() override;

	void OnPaint   (shared_ptr<XLibGC> _GC) override;

	void Test();
	void TestGC_01();

	static void Run();

private:
	void DrawPoint(shared_ptr<XLibGC> _GC, int x, int y);

};



#endif /* WAVESHAREEMULATOR_H_ */
