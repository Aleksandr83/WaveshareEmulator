// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SYSTEM_TYPES_GENERIC_INC_DATABUFFER_H_
#define SYSTEM_TYPES_GENERIC_INC_DATABUFFER_H_

#include "PreCompiller.h"


#pragma once


namespace OS {
namespace Types {
namespace Generic {

template<class T,class S>
class DataBuffer {
private:
	T*   _Data;
	S    _Size;
public:
	DataBuffer();
	virtual ~DataBuffer();

	virtual uint32_t GetSize();
	virtual void     SetSize(S size);
	virtual T		 GetValue(S index);
	virtual void     SetValue(T value, S index);
	virtual void     Clear(S count = 0, T value = 0);
	virtual void     Copy (S startPos, void* dest,S destStartPos, S length);
	virtual void     InsertArray(S startPos,void* source, S sourceStartPos, S length);
	virtual T*       GetDataPointer();

private:
	void Create();
	void Delete();

};


}}}

#include "../dataBuffer.tpp"

#endif /* SYSTEM_TYPES_GENERIC_INC_DATABUFFER_H_ */
