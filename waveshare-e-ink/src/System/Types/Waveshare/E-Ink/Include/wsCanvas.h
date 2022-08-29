// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_WAVESHARE_E_INK_WSCANVAS_H_
#define SRC_SYSTEM_TYPES_WAVESHARE_E_INK_WSCANVAS_H_


#include "canvas.h"
#include "PreCompiller.h"


#pragma once


namespace GUI {
namespace Waveshare {
namespace EInk {

using GUI::Canvas;

class WsCanvas : public Canvas<uint8_t, uint16_t>
{
private:
	Size<uint16_t>  _SizeInBytes;

public:
	WsCanvas();
	virtual ~WsCanvas();

	virtual uint32_t GetPixel(uint32_t x, uint32_t y)				  override;
	virtual void 	 SetPixel(uint32_t x, uint32_t y, uint32_t color) override;

protected:
	virtual void 	 NewImage() override;

//private:
//	void GetRotatePointXY(Point<uint32_t>* point, uint32_t x, uint32_t y);
//	void GetMirrorPointXY(Point<uint32_t>* point, uint32_t x, uint32_t y);

};

}}}

#endif /* SRC_SYSTEM_TYPES_WAVESHARE_E_INK_WSCANVAS_H_ */
