// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "dataBuffer.h"
#include "array.h"

namespace OS {
namespace Types {
namespace Generic {

template<class T,class S>
DataBuffer<T,S>::DataBuffer()
{
	_Data = NULL;
}

template<class T,class S>
uint32_t DataBuffer<T,S>::GetSize()
{
	return _Size;
}

template<class T,class S>
void DataBuffer<T,S>::SetSize(S size)
{
	Delete();
	_Size = size;
	Create();
}

template<class T,class S>
T DataBuffer<T,S>::GetValue(S index)
{
	return *(_Data + index);
}

template<class T,class S>
void DataBuffer<T,S>::SetValue(T value, S index)
{
	*(_Data + index) = value;
}

template<class T,class S>
void DataBuffer<T,S>::Clear(S count, T value)
{
	S size = (count == 0)? _Size : count;
	OS::Types::Generic::Array<T> array;
	array.Clear(_Data, size, value);
}

template<class T,class S>
void DataBuffer<T,S>::Copy (S startPos, void* dest,S destStartPos, S length)
{
	OS::Types::Generic::Array<T> array;
	array.Copy(GetDataPointer(),startPos, dest, destStartPos, length);
}

template<class T,class S>
void DataBuffer<T,S>::InsertArray(S startPos,void* source, S sourceStartPos, S length)
{
	OS::Types::Generic::Array<T> array;
	array.Copy(source, sourceStartPos, GetDataPointer(), startPos, length);
}

template<class T,class S>
T* DataBuffer<T,S>::GetDataPointer()
{
	T* result = (T*)_Data;
	return  result;
}

template<class T,class S>
void DataBuffer<T,S>::Create()
{
	if (_Data != NULL) return;
	if (_Size == 0)    return;
	_Data = (T*) new T[_Size];
}

template<class T,class S>
void DataBuffer<T,S>::Delete()
{
	if (_Data == NULL) return;
	delete _Data;
}

template<class T,class S>
DataBuffer<T,S>::~DataBuffer()
{
	Delete();
}

}}}
