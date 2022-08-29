// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GUI_GENERICCRC_H_
#define SRC_SYSTEM_TYPES_GUI_GENERICCRC_H_


#include "PreCompiller.h"
#ifndef PC
#include "crcDevice.h"
#endif

#pragma once


namespace OS {
namespace Types {
namespace Generic {

#ifndef PC
using Drivers::CrcDevice;
#endif

template <class T, class S>
class GenericCRC
{
private:
	T 		 _LastCRC;
	uint8_t* _DataPointer;
	S		 _Start;
	S        _Length;

#ifndef PC
	CrcDevice<T,S>* _CrcDevice;
#endif

public:
	GenericCRC();
	GenericCRC(uint8_t* data, S start, S length);
	virtual ~GenericCRC();

	virtual void ResetLastCRC();
#ifndef PC
	virtual void SetCrcDevice(CrcDevice<T,S>* crcDevice);
#endif
	virtual void SetDataPointer(uint8_t* data);
	virtual void SetDataLength (S length);

	virtual bool IsEqualWithLastCRC();

	virtual T CalcBytes();
	virtual T CalcBytes(uint8_t *data, S start, S length);

};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../genericCRC.tpp"

#endif /* SRC_SYSTEM_TYPES_GUI_GENERICCRC_H_ */
