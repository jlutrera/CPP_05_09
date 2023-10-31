#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : _value(T())
{
}

template <typename T>
PmergeMe<T>::PmergeMe(T const &value) : _value(value)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &src) : _value(src._value)
{
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs._value;
	}
	return (*this);
}

template <typename T>
T const &PmergeMe<T>::getValue() const
{
	return (this->_value);
}

template <typename T>
void PmergeMe<T>::setValue(T const &value)
{
	this->_value = value;
}
