// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "wsEInkGC.h"
#include "bits.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"

namespace GUI {
namespace Waveshare {
namespace EInk {

WsEInkGC::WsEInkGC(uint32_t width, uint32_t height)
  :GC<uint32_t, WsCanvas>(width, height)
{
	Init();
}

void WsEInkGC::Init()
{
	GC<uint32_t, WsCanvas>::Init();
	this->GetCanvas()->SetRotateAngle((int)TRotate::d270);
	//SetColor((int)TColor::Black);
	SetDotPixel((int)TDotPixel::DOT_PIXEL_1X1);
	SetDotStyle((int)TDotStyle::FillRightup);
	SetLineStyle((int)TLineStyle::Solid);
	SetIsDrawFill((int)TDrawFill::FillEmpty);
}

void WsEInkGC::Clear()
{
	Clear(TColor::White);
}

void WsEInkGC::Clear(TColor color)
{
	// scale == 2 || 4
//	for (uint16_t y = 0; y < _Paint.HeightByte; y++)
//	{
//		for (uint16_t x = 0; x < _Paint.WidthByte; x++ )
//		{
//			//8 pixel =  1 byte
//			uint32_t addr = x + y * _Paint.WidthByte;
//			_Paint.Image[addr] = color;
//		}
//	}
}

//void WsEInkGC::NewImage(uint8_t *image, uint32_t width, uint32_t height, uint32_t rotate, uint32_t color)
//{
//	_Paint.Image 		= image;
//	_Paint.WidthMemory 	= width;
//	_Paint.HeightMemory = height;
//	_Paint.Color        = color;
//	_Paint.Scale		= 2;
//	_Paint.WidthByte    = (width % 8 == 0)? (width / 8 ): (width / 8 + 1);
//	_Paint.HeightByte   = height;
//	_Paint.Rotate 		= rotate;
//	_Paint.Mirror 		= TMirror::mNone;
//
//	if(rotate == TRotate::d0 || rotate == TRotate::d180)
//	{
//	   _Paint.Width  = width;
//	   _Paint.Height = height;
//	}
//	else
//	{
//	   _Paint.Width  = height;
//	   _Paint.Height = width;
//	}
//}



WsCanvas* WsEInkGC::CreateCanvas()
{
	return new WsCanvas();
}

WsEInkGC::~WsEInkGC()
{

}

}}}
