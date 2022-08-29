// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef OS_TYPES_GENERIC_PINSWITCHER_H_
#define OS_TYPES_GENERIC_PINSWITCHER_H_

#include "PreCompiller.h"
#ifndef PC
#include "pio.h"
#include "switcher.h"
#endif

#pragma once


namespace OS {
namespace Types {
namespace Generic {

#ifndef PC

using Drivers::Generic::Pio;
using OS::Types::Generic::Switcher;

class PinSwitcher : public Switcher{
private:
	Pio*        _Pio;
	GpioPinType _Pin;

public:
	PinSwitcher(Pio *pio, int pin);
	virtual ~PinSwitcher();

	virtual void On()  override;
	virtual void Off() override;

protected:
	virtual Pio*        GetPortIO();
	virtual GpioPinType GetPin();
};

#endif

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#endif /* OS_TYPES_GENERIC_PINSWITCHER_H_ */
