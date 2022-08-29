// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_CANVAS_H_
#define SRC_SYSTEM_TYPES_GUI_CANVAS_H_


#include "size.h"
#include "rotate.h"
#include "shapeColor.h"
#include "PreCompiller.h"
#include "point.h"

#pragma once


namespace GUI {

using GUI::Rotate;
using GUI::ShapeColor;

template <class T, class TSize>
class Canvas : public Size<TSize>, public Rotate, public ShapeColor
{
private:
	T* 		 		_ImageBuffer;
	uint32_t 		_ImageBufferLength;

protected:
	Size<uint32_t> 	_SizeImageMemory;
	Size<uint32_t> 	_SizePaint;

public:
	Canvas();
	virtual ~Canvas();

	virtual T* 		 GetImageBuffer() const;
	virtual uint32_t GetImageBufferLength()const;

	virtual void     AttachImageBuffer(T* imageBuffer, uint32_t imageBufferLength);

	virtual uint32_t GetPixel(uint32_t x, uint32_t y)				  = 0;
	virtual void 	 SetPixel(uint32_t x, uint32_t y, uint32_t color) = 0;

protected:
	virtual void 	 NewImage();
	virtual void 	 GetRotatePointXY(Point<TSize>* point, TSize x, TSize y);
	virtual void 	 GetMirrorPointXY(Point<TSize>* point, TSize x, TSize y);

};

} /* namespace GUI */

#include "../canvas.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_CANVAS_H_ */
