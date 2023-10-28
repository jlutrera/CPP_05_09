#include "whatever.hpp"
#include <iostream>

class Awesome
{
	public:
		Awesome():_n(0){}
		Awesome(int n):_n(n){}
		Awesome & operator = (Awesome & rhs)
		{
			_n = rhs._n;
			return *this;
		}
		bool operator == (Awesome & rhs)
		{
			return _n == rhs._n;
		}
		bool operator != (Awesome & rhs)
		{
			return _n != rhs._n;
		}
		bool operator > (Awesome & rhs)
		{
			return _n > rhs._n;
		}
		bool operator < (Awesome & rhs)
		{
			return _n < rhs._n;
		}
		bool operator >= (Awesome & rhs)
		{
			return _n >= rhs._n;
		}
		bool operator <= (Awesome & rhs)
		{
			return _n <= rhs._n;
		}
		int get_n() const
		{
			return _n;
		}
	private:

		int _n;
};

std::ostream & operator << (std::ostream & o, Awesome & rhs)
{
	o << rhs.get_n();
	return o;
}

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;

	Awesome a(2), b(4);

	std::cout << "a = " << a << ", b = " << b<< std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b<< std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	return (0);
}