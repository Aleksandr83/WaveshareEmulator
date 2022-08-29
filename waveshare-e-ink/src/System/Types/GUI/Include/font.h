// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_FONT_H_
#define SRC_SYSTEM_TYPES_GUI_FONT_H_


#include "PreCompiller.h"
#include "size.h"
#include "length.h"

#pragma once


namespace GUI {

using GUI::Size;
using OS::Types::Generic::Length;

class Font : public Size<uint8_t>, protected Length<uint32_t>
{
private:
	uint8_t* _Table;
	string   _FontName;

public:
	Font();
	virtual ~Font();

	uint8_t* GetTablePtr() const;
	uint8_t  GetWidthInBytes();

protected:
	virtual void     SetWidth (uint8_t value)  override;
	virtual void     SetHeight(uint8_t value)  override;
	virtual void     SetFontName(string value);
	virtual void     SetTablePtr(uint8_t* value);

};

} /* namespace XLib */

#endif /* SRC_SYSTEM_TYPES_GUI_FONT_H_ */
