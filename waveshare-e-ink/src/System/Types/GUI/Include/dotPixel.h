// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_DOTPIXEL_H_
#define SRC_SYSTEM_TYPES_GUI_DOTPIXEL_H_


#pragma once


namespace GUI {

template <class T>
class DotPixel
{
private:
	T _DotPixel;

public:
	DotPixel();
	virtual ~DotPixel();

	virtual T 	  GetDotPixel() const;
	virtual void  SetDotPixel (T dotPixel);
};

} /* namespace GUI */

#include "../dotPixel.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_DOTPIXEL_H_ */
