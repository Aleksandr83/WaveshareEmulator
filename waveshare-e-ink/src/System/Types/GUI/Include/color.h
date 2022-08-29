// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GENERIC_COLOR_H_
#define SRC_SYSTEM_TYPES_GENERIC_COLOR_H_


#include "PreCompiller.h"
#include "defaultValue.h"


#pragma once


namespace GUI {

using OS::Types::Generic::DefaultValue;

template <class T>
class Color : public DefaultValue<T>
{
public:
	Color();
	virtual ~Color();
};

}

#include "../color.tpp"

#endif /* SRC_SYSTEM_TYPES_GENERIC_COLOR_H_ */
