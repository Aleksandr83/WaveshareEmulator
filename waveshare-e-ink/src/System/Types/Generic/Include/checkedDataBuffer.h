// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SRC_SYSTEM_TYPES_GENERIC_CHECKEDDATABUFFER_H_
#define SRC_SYSTEM_TYPES_GENERIC_CHECKEDDATABUFFER_H_


#include "dataBuffer.h"
#include "genericCRC.h"

#pragma once


namespace OS {
namespace Types {
namespace Generic {


using OS::Types::Generic::DataBuffer;
using OS::Types::Generic::GenericCRC;

template <class T, class S, class Crc>
class CheckedDataBuffer : public DataBuffer<T,S>, protected GenericCRC<Crc,S>
{
public:
	CheckedDataBuffer();
	virtual ~CheckedDataBuffer();

	virtual void SetCrcDevice(CrcDevice<Crc,S>* crcDevice);
	virtual void ResetLastCRC();

	virtual void SetSize(S size) override;
	virtual bool IsWasChanged();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../checkedDataBuffer.tpp"

#endif /* SRC_SYSTEM_TYPES_GENERIC_CHECKEDDATABUFFER_H_ */
