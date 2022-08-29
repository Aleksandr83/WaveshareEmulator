// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com

#include "genericCRC.h"

namespace OS {
namespace Types {
namespace Generic {


template <class T, class S>
GenericCRC<T,S>::GenericCRC()
  :_LastCRC(0), _DataPointer(NULL), _Start(0), _Length(0), _CrcDevice(NULL)
{

}

template <class T, class S>
GenericCRC<T,S>::GenericCRC(uint8_t* data, S start, S length)
  :_LastCRC(0), _DataPointer(data), _Start(start), _Length(length)
{

}

#ifndef PC
template <class T, class S>
void GenericCRC<T,S>::SetCrcDevice(CrcDevice<T,S>* crcDevice)
{
	_CrcDevice = crcDevice;
}
#endif

template <class T, class S>
void GenericCRC<T,S>::ResetLastCRC()
{
	_LastCRC = 0;
}

template <class T, class S>
void GenericCRC<T,S>::SetDataPointer(uint8_t* data)
{
	_DataPointer = data;
}

template <class T, class S>
void GenericCRC<T,S>::SetDataLength (S length)
{
	_Length = length;
}

template <class T, class S>
bool GenericCRC<T,S>::IsEqualWithLastCRC()
{
	T crc = CalcBytes(_DataPointer, _Start, _Length);
	if (crc == _LastCRC) return true;
	_LastCRC = crc;
	return false;
}

template <class T, class S>
T GenericCRC<T,S>::CalcBytes()
{
	return CalcBytes(_DataPointer, _Start, _Length);
}

template <class T, class S>
T GenericCRC<T,S>::CalcBytes(uint8_t *data, S start, S length)
{
#ifndef PC
	if (_CrcDevice != NULL)
	{
		return _CrcDevice->CalcCRC(data, start, length);
	}
#endif
	return 0;
}

template <class T, class S>
GenericCRC<T,S>::~GenericCRC()
{

}

}}}


