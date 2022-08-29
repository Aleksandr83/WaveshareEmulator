// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_WAVESHARE_E_INK_WSEINKGC_H_
#define SRC_SYSTEM_TYPES_WAVESHARE_E_INK_WSEINKGC_H_


#include "PreCompiller.h"
#include "wsCanvas.h"
#include "gc.h"



#pragma once


namespace GUI {
namespace Waveshare {
namespace EInk {

using GUI::GC;
using GUI::Canvas;
using GUI::Waveshare::EInk::WsCanvas;

class WsEInkGC : public GC<uint32_t, WsCanvas>
{
public:
	enum class TColor
	{
		White      = 0x00,
		Black      = 0xFF,
		ThirdColor = Black
	};

	enum class TDotPixel
	{
		DOT_PIXEL_1X1  = 1,		// 1 x 1
		DOT_PIXEL_2X2  , 		// 2 X 2
		DOT_PIXEL_3X3  ,		// 3 X 3
		DOT_PIXEL_4X4  ,		// 4 X 4
		DOT_PIXEL_5X5  , 		// 5 X 5
		DOT_PIXEL_6X6  , 		// 6 X 6
		DOT_PIXEL_7X7  , 		// 7 X 7
		DOT_PIXEL_8X8  , 		// 8 X 8

	};

	const TDotPixel  __DEFAULT_DOT_PIXEL  = TDotPixel::DOT_PIXEL_1X1;
	const TDotStyle  __DEFAULT_DOT_STYLE  = TDotStyle::FillAround;

private:
	TColor 		_Background;
	TColor 		_Foreground;

public:
	WsEInkGC(uint32_t width, uint32_t height);
	virtual ~WsEInkGC();

	virtual void Init() override;

	virtual void Clear() override;

protected:
	void Clear(TColor color);

	virtual WsCanvas* CreateCanvas() override;
};

}}}

#endif /* SRC_SYSTEM_TYPES_WAVESHARE_E_INK_WSEINKGC_H_ */
