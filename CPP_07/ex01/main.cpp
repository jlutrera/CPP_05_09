#include "iter.hpp"

class Awesome
{
	public:
		Awesome():_n(42){return;}
		int get() const {return _n;}
	private:
		int _n;
};

std::ostream & operator << (std::ostream & o, Awesome const & rhs)
{
	o << rhs.get();
	return o;
}

template <typename T>
void print(T const & x)
{
	std::cout << x << std::endl;
	return;
}

int main()
{
	int int_array[5] = {1, 2, 3, 4, 5};
	std::string string_array[5] = {"one", "two", "three", "four", "five"};

	std::cout << "int_array: " << std::endl;
	iter(int_array, 5, print);
	std::cout << std::endl;
	std::cout << "string_array: " << std::endl;
	iter(string_array, 5, print);
	std::cout << std::endl;

	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);
	
	return (0);
}
