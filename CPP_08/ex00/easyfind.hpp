#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

/**
 * @brief Template function to find the first occurrence of an integer in a container
 *
 * @tparam T The container type
 * @param container The container to search in
 * @param value The integer value to find
 * @return Iterator to the first occurrence of the value
 * @throw std::runtime_error if the value is not found
 */
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found in container");

	return it;
}

#endif