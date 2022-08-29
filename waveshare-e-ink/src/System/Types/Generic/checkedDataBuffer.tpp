// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "checkedDataBuffer.h"


namespace OS {
namespace Types {
namespace Generic {


template <class T, class S, class Crc>
CheckedDataBuffer<T,S,Crc>::CheckedDataBuffer()
  :DataBuffer<T,S>(), GenericCRC<Crc,S>()
{

}

template <class T, class S, class Crc>
void CheckedDataBuffer<T,S,Crc>::SetCrcDevice(CrcDevice<Crc,S>* crcDevice)
{
	GenericCRC<Crc,S>::SetCrcDevice((CrcDevice<Crc,S>*)crcDevice);
}

template <class T, class S, class Crc>
void CheckedDataBuffer<T,S,Crc>::SetSize(S size)
{
	DataBuffer<T,S>::SetSize(size);
	GenericCRC<Crc,S>::SetDataPointer(this->GetDataPointer());
	GenericCRC<Crc,S>::SetDataLength(size);
}

template <class T, class S, class Crc>
void CheckedDataBuffer<T,S,Crc>::ResetLastCRC()
{
	GenericCRC<Crc,S>::ResetLastCRC();
}

template <class T, class S, class Crc>
bool CheckedDataBuffer<T,S,Crc>::IsWasChanged()
{
	return !GenericCRC<Crc,S>::IsEqualWithLastCRC();
	return true;
}

template <class T, class S, class Crc>
CheckedDataBuffer<T,S,Crc>::~CheckedDataBuffer()
{

}

}}}
