// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_DOTSTYLE_H_
#define SRC_SYSTEM_TYPES_GUI_DOTSTYLE_H_


#pragma once


namespace GUI {

template <class T>
class DotStyle
{
public:
	enum class TDotStyle
	{
		FillAround = 1, // dot pixel 1 x 1
		FillRightup		// dot pixel 2 X 2
	};


private:
	T _DotStyle;

public:
	DotStyle();
	virtual ~DotStyle();

	virtual T 	  GetDotStyle() const;
	virtual void  SetDotStyle (T dotStyle);
};

}

#include "../dotStyle.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_DOTSTYLE_H_ */
