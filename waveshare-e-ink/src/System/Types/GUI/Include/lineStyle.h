// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_LINESTYLE_H_
#define SRC_SYSTEM_TYPES_GUI_LINESTYLE_H_

namespace GUI {

template <class T>
class LineStyle
{
public:
	enum class TLineStyle
	{
		Solid = 0,
		Dotted,
	};

private:
	T _LineStyle;

public:
	LineStyle();
	virtual ~LineStyle();

	virtual T    GetLineStyle()const;
	virtual void SetLineStyle(T lineStyle);
};

} /* namespace GUI */

#include "../lineStyle.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_LINESTYLE_H_ */
