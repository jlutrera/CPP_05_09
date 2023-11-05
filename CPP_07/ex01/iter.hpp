#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T const *array, int const length, void (*f)(T const &))
{
	for (int i = 0; i < length; i++)
		f(array[i]);	
}

#endif
