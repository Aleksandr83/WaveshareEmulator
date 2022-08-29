// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_ROTATE_H_
#define SRC_SYSTEM_TYPES_GUI_ROTATE_H_


#include "PreCompiller.h"


#pragma once


namespace GUI {

class Rotate {
public:
	enum class TRotate
	{
		angle0   = 0,
		angle90  = 90,
		angle180 = 180,
		angle270 = 270
	};

private:
	uint16_t _Angle;

public:
	Rotate();
	virtual ~Rotate();

	virtual uint16_t GetRotateAngle() const;
	virtual void     SetRotateAngle(uint16_t angle);
};

} /* namespace GUI */

#endif /* SRC_SYSTEM_TYPES_GUI_ROTATE_H_ */
