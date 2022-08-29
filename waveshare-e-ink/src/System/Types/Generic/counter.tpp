// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "counter.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
Counter<T>::Counter()
	: LimitedValue<T>(), _IsCyclic(false)
{
}

template <class T>
void Counter<T>::Inc()
{
	Counter<T>::operator ++();
}

template <class T>
void Counter<T>::Dec()
{
	Counter<T>::operator --();
}

template <class T>
T Counter<T>::operator++()
{
	if (!this->IsSetRange() || !_IsCyclic)
		return LimitedValue<T>::operator ++();

	LimitedValue<T>::operator ++();
	if (this->IsMaxLimit())
		this->SetMinValue();

	return this->GetValue();
}

template <class T>
T Counter<T>::operator--()
{
	if (!this->IsSetRange() || !_IsCyclic)
		return LimitedValue<T>::operator --();

	LimitedValue<T>::operator --();
	if (this->IsMinLimit())
		this->SetMaxValue();

	return this->GetValue();
}

template <class T>
void Counter<T>::SetCyclicValue(bool value)
{
	_IsCyclic = true;
}

template <class T>
Counter<T>::~Counter()
{

}

}}}
