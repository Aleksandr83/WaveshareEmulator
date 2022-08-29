// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_SIZE_H_
#define SRC_SYSTEM_TYPES_GUI_SIZE_H_


#include "PreCompiller.h"


#pragma once


namespace GUI {

template <class T>
class Size
{
private:
	T  _Width;
	T  _Height;

public:
	Size();
	Size(T width, T height);
	virtual ~Size();

	virtual T    GetWidth()  const;
	virtual void SetWidth (T value);
	virtual T    GetHeight() const;
	virtual void SetHeight(T value);
};

}

#include "../size.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_SIZE_H_ */
