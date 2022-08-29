// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef SYSTEM_TYPES_GENERIC_ARRAY_H_
#define SYSTEM_TYPES_GENERIC_ARRAY_H_

#include "PreCompiller.h"


#pragma once


namespace OS {
  namespace Types {
    namespace Generic {

template<class T>
class Array {
public:
	static void Clear(void* array, int count, T defaultValue);
	static void Copy (void* source, int sourceStartPos, void* dest,int destStartPos, int length);

};

template<class T>
void Array<T>::Clear(void* array,int count,T defaultValue)
{
    T *p = (T*)array;
    for (int i = 0; i < count; i++)
    {
    	*(p+i)=defaultValue;
    }
}

template<class T>
void Array<T>::Copy(void* source, int sourceStartPos, void* dest,int destStartPos, int length)
{
	T  value;
	int n = 0;
	int i = sourceStartPos;
	int j = destStartPos;
	if (source == NULL) return;
	if (dest   == NULL) return;
	T* p1 = (T*)source;
	T* p2 = (T*)dest;
	while (n < length)
	{
		value = *(p1 + i);
		*(p2 + j) = value;
		n++;
		i++;
		j++;
	}
}

}}}

#endif /* SYSTEM_TYPES_GENERIC_ARRAY_H_ */
