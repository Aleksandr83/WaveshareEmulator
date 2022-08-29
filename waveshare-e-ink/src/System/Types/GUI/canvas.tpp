// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "canvas.h"

namespace GUI {

template <class T, class TSize>
Canvas<T, TSize>::Canvas()
  :Size<TSize>(), Rotate(), ShapeColor(),
   _ImageBuffer(NULL), _ImageBufferLength(0)
{

}

template <class T, class TSize>
T* Canvas<T, TSize>::GetImageBuffer()const
{
	return _ImageBuffer;
}

template <class T, class TSize>
uint32_t Canvas<T, TSize>::GetImageBufferLength()const
{
	return _ImageBufferLength;
}

template <class T, class TSize>
void Canvas<T, TSize>::AttachImageBuffer(T* imageBuffer, uint32_t imageBufferLength)
{
	_ImageBuffer       = imageBuffer;
	_ImageBufferLength = imageBufferLength;
	NewImage();
}

template <class T, class TSize>
void Canvas<T, TSize>::NewImage()
{
	_SizeImageMemory.SetWidth(this->GetWidth());
	_SizeImageMemory.SetHeight(this->GetHeight());

	auto rotateAngle = GetRotateAngle();

	if(rotateAngle == (int)TRotate::angle0 || rotateAngle == (int)TRotate::angle180)
	{
		_SizePaint.SetWidth (this->GetWidth());
		_SizePaint.SetHeight(this->GetHeight());
	}
	else
	{
		_SizePaint.SetWidth (this->GetHeight());
		_SizePaint.SetHeight(this->GetWidth());
	}
}

template <class T, class TSize>
void Canvas<T, TSize>::GetRotatePointXY(Point<TSize>* point, TSize x, TSize y)
{
	auto rotateAngle = GetRotateAngle();

	if (rotateAngle == (int)TRotate::angle0)
	{
		point->SetX(x);
		point->SetY(y);
		return;
	}
	if (rotateAngle == (int)TRotate::angle90)
	{
		point->SetX(_SizeImageMemory.GetWidth() - y - 1);
		point->SetY(x);
		return;
	}
	if (rotateAngle == (int)TRotate::angle180)
	{
		point->SetX(_SizeImageMemory.GetWidth()  - x - 1);
		point->SetY(_SizeImageMemory.GetHeight() - y - 1);
		return;
	}
	if (rotateAngle == (int)TRotate::angle270)
	{
		point->SetX(y);
		point->SetY(_SizeImageMemory.GetHeight() - x - 1);
		return;
	}
}

template <class T, class TSize>
void Canvas<T, TSize>::GetMirrorPointXY(Point<TSize>* point, TSize x, TSize y)
{
	//	if (_Paint.Mirror == TMirror::mNone) return;
	//	if (_Paint.Mirror == TMirror::Horizontal)
	//	{
	//		point->SetX(_Paint.WidthMemory  - x - 1);
	//		return;
	//	}
	//	if (_Paint.Mirror == TMirror::Vertical)
	//	{
	//		point->SetY(_Paint.HeightMemory - y - 1);
	//		return;
	//	}
	//	if (_Paint.Mirror == TMirror::Origin)
	//	{
	//		point->SetX(_Paint.WidthMemory  - x - 1);
	//		point->SetY(_Paint.HeightMemory - y - 1);
	//		return;
	//	}
}

template <class T, class TSize>
Canvas<T, TSize>::~Canvas()
{

}

}
