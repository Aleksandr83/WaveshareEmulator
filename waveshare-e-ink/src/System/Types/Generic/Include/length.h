// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GENERIC_LENGTH_H_
#define SRC_SYSTEM_TYPES_GENERIC_LENGTH_H_

#include "PreCompiller.h"


#pragma once


namespace OS {
namespace Types {
namespace Generic {

template <class T>
class Length {
private:
	T _Length;

public:
	Length();
	virtual ~Length();

	virtual T GetLength() const;
	virtual T SetLength(T value);
};

}}}

#include "../length.tpp"

#endif /* SRC_SYSTEM_TYPES_GENERIC_LENGTH_H_ */
