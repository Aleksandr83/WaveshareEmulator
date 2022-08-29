// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "wsCanvas.h"
#include "point.h"
#include "bits.h"


namespace GUI {
namespace Waveshare {
namespace EInk {

WsCanvas::WsCanvas()
  :Canvas<uint8_t, uint16_t>()
{

}

uint32_t WsCanvas::GetPixel(uint32_t x, uint32_t y)
{
	uint32_t result = 0xFF;

	if(x > _SizePaint.GetWidth() || y > _SizePaint.GetHeight()) return result;

	Point<uint16_t> point;
	GetRotatePointXY(&point, x, y);
	GetMirrorPointXY(&point, point.GetX(), point.GetY());

	if (point.GetX() > _SizeImageMemory.GetWidth() || point.GetY() > _SizeImageMemory.GetHeight())
		return result;

	// scale = 2
	uint32_t addr  = (point.GetX() / 8 + point.GetY() * _SizeInBytes.GetWidth()) ;
	auto     bit   = 8-(point.GetX() % 8 + 1);
	auto*    image = GetImageBuffer();

	if (__IS_SET_BIT(image[addr],bit))
		result = 0x00;

	return result;
}

void WsCanvas::SetPixel(uint32_t x, uint32_t y, uint32_t color)
{
	if(x > _SizePaint.GetWidth() || y > _SizePaint.GetHeight()) return;

	Point<uint16_t> point;
	GetRotatePointXY(&point, x, y);
	GetMirrorPointXY(&point, point.GetX(), point.GetY());

	if (point.GetX() > _SizeImageMemory.GetWidth() || point.GetY() > _SizeImageMemory.GetHeight())
		return;

	// scale = 2
	uint32_t addr  = (point.GetX() / 8 + point.GetY() * _SizeInBytes.GetWidth()) ;
	auto     bit   = 8-(point.GetX() % 8 + 1);
	auto*    image = GetImageBuffer();

	if(color == 0x00)  //if(color == TColor::Black)
		__SET_BIT  (image[addr], bit);
	else
		__RESET_BIT(image[addr], bit);
}

void WsCanvas::NewImage()
{
	Canvas<uint8_t, uint16_t>::NewImage();
	auto width = this->GetWidth();
	_SizeInBytes.SetWidth((width % 8 == 0)? (width / 8 ): (width / 8 + 1));
	_SizeInBytes.SetHeight(this->GetHeight());
}

WsCanvas::~WsCanvas()
{

}

}}}
