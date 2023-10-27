#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const &src) : _array(NULL), _size(0) { *this = src; }
		~Array(void) { delete [] _array; }

		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete [] _array;
				_size = rhs._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			return (_array[i]);
		}

		unsigned int size(void) const { return (_size); }

	private:
		T *_array;
		unsigned int _size;
};

#endif