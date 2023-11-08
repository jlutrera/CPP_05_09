#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array<T>(void) : _array(NULL), _size(0)
		{
			std::cout << "An empty array has been created" << std::endl;
		}
		Array<T>(unsigned int const n) : _array(new T[n]), _size(n)
		{
			std::cout << "An array of size " << n << " has been created" << std::endl;
		}
		Array<T>(Array<T> const &src) : _array(NULL), _size(0)
		{
			std::cout << "An array has been created by copy" << std::endl;
			*this = src;
		}
		~Array<T>(void)
		{
			std::cout << "An array has been destroyed" << std::endl;
			if (_array)
				delete [] _array;
		}
		Array<T> &operator=(Array<T> const &rhs)
		{
			std::cout << "An array has been assigned" << std::endl;
			if (this != &rhs)
			{
				if (_array)
					delete [] _array;
				_size = rhs._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}
		T &operator[](unsigned int const i) const
		{
			if (i >= _size)
				throw std::exception();
			return (_array[i]);
		}
		unsigned int size(void) const
		{
			return (_size);
		}

	private:
		T *_array;
		unsigned int _size;
};

#endif
