#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
	if (array == NULL)
		return;

	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

#endif