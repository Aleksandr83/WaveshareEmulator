// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_FONTS_FONT16_H_
#define SRC_SYSTEM_TYPES_GUI_FONTS_FONT16_H_

#include "PreCompiller.h"
#include "font.h"

#pragma once

namespace GUI {
namespace FONTS {

using GUI::Font;


class Font16 : public Font
{
public:
	Font16();
	virtual ~Font16();
};

}}

#endif /* SRC_SYSTEM_TYPES_GUI_FONTS_FONT16_H_ */
