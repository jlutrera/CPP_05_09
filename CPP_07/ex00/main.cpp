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
		bool operator == (Awesome & rhs) { return _n == rhs._n; }
		bool operator != (Awesome & rhs) { return _n != rhs._n; }
		bool operator > (Awesome & rhs)  { return _n > rhs._n; 	}
		bool operator < (Awesome & rhs)  { return _n < rhs._n;  }
		bool operator >= (Awesome & rhs) { return _n >= rhs._n;	}
		bool operator <= (Awesome & rhs) { return _n <= rhs._n; }
		int get_n() const {	return _n; }
	private:
		int _n;
};

std::ostream & operator << (std::ostream & o, const Awesome & rhs)
{
	o << rhs.get_n();
	return o;
}

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << CYAN << "\n****** <int> type ******" << RESET << std::endl;
	std::cout << "TEST swap function: " << std::endl;
	std::cout << "  Before: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "  After : a = " << a << ", b = " << b << std::endl;
	std::cout << "TEST min and max functions:" << std::endl;
	std::cout << "  min(a, b) = " << min(a, b) << std::endl;
	std::cout << "  max(a, b) = " << max(a, b) << std::endl;

	std::string c = "first ";
	std::string d = "second";

	std::cout << CYAN << "\n****** <string> type ******" << RESET << std::endl;
	std::cout << "TEST swap function" << std::endl;
	std::cout << "  Before: c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "  After : c = " << c << ", d = " << d << std::endl;
	std::cout << "TEST min and max functions:" << std::endl;
	std::cout << "  min(c, d) = " << min(c, d) << std::endl;
	std::cout << "  max(c, d) = " << max(c, d) << std::endl;

	Awesome x(2), y(4);

	std::cout << CYAN << "\n****** <Awesome> class ******" << RESET << std::endl;
	std::cout << "TEST swap function: " << std::endl;
	std::cout << "  Before: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "  After : x = " << x << ", y = " << y << std::endl;
	std::cout << "TEST min and max functions:" << std::endl;
	std::cout << "  min(x, y) = " << min(x, y) << std::endl;
	std::cout << "  max(x, y) = " << max(x, y) << std::endl;

	return (0);
}
