// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_SHAPEFILL_H_
#define SRC_SYSTEM_TYPES_GUI_SHAPEFILL_H_


#include "PreCompiller.h"


#pragma once


namespace GUI {

class ShapeFill
{
public:
	enum class TDrawFill
	{
	    FillEmpty = 0,
		FillFull,
	};

private:
	bool _IsDrawFill;

public:
	ShapeFill();
	virtual ~ShapeFill();

	virtual bool GetIsDrawFill() const;
	virtual void SetIsDrawFill(bool isDrawFill);
};

} /* namespace GUI */

#endif /* SRC_SYSTEM_TYPES_GUI_SHAPEFILL_H_ */
