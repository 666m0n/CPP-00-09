#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
	T* _elements;
	unsigned int _size;

public:
	Array() : _elements(NULL), _size(0) {}

	Array(unsigned int n) : _size(n)
	{
		_elements = new T[n]();
	}

	Array(Array const &src) : _elements(NULL), _size(0)
	{
		*this = src;
	}

	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			if (_elements)
				delete[] _elements;

			_size = rhs._size;
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = rhs._elements[i];
		}
		return *this;
	}

	~Array()
	{
		if (_elements)
			delete[] _elements;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _elements[index];
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _elements[index];
	}

	unsigned int size() const
	{
		return _size;
	}
};

#endif