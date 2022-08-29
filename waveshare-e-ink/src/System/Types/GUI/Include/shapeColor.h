// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_SHAPECOLOR_H_
#define SRC_SYSTEM_TYPES_GUI_SHAPECOLOR_H_


#include "PreCompiller.h"
#include "color.h"

#pragma once


namespace GUI {

using GUI::Color;

class ShapeColor {
private:
	//uint32_t _Color;
	Color<uint32_t> _Background;
	Color<uint32_t> _Foreground;

public:
	ShapeColor();
	virtual ~ShapeColor();

	virtual Color<uint32_t>* GetBackground();
	virtual Color<uint32_t>* GetForeground();

	virtual void SetColor(ShapeColor* color);
	//virtual Color<uint32_t>*
	//virtual uint32_t GetColor() const;
	//virtual void     SetColor(uint32_t color);
};

} /* namespace GUI */

#endif /* SRC_SYSTEM_TYPES_GUI_SHAPECOLOR_H_ */
