// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "pinSwitcher.h"
#include <stddef.h>
#ifndef PC
#include "Gpio.h"
#endif


namespace OS {
namespace Types {
namespace Generic {

#ifndef PC

using Drivers::Generic::Gpio;
using Drivers::Generic::TPinDirection;


PinSwitcher::PinSwitcher(Pio *pio, int pin)
	: Switcher()
{
	_Pin = pin;
	_Pio = (pio == NULL)? new Gpio() : pio;
	_Pio->SetPinDirection(TPinDirection::Output , _Pin);
}

void PinSwitcher::On()
{
	Pio* portIO = GetPortIO();
	portIO->SetPin(GetPin());
}

void PinSwitcher::Off()
{
	Pio* portIO = GetPortIO();
	portIO->ResetPin(GetPin());
}

Pio* PinSwitcher::GetPortIO()
{
	return _Pio;
}

GpioPinType PinSwitcher::GetPin()
{
	return _Pin;
}

PinSwitcher::~PinSwitcher()
{

}

#endif

}}}
