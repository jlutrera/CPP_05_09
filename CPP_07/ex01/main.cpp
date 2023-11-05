#include "iter.hpp"

class Awesome
{
	public:
		Awesome():_n(42){}
		int get() const { return _n; }
	private:
		int _n;
};
std::ostream & operator << (std::ostream & o, const Awesome & rhs)
{
	o << rhs.get();
	return o;
}

//Some template functions to test the iter function
template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void next(T &x)
{
	std::cout << x + 1 << std::endl;
}


template <typename T>
void upper(T &x)
{
	std::cout << static_cast<char>(x - 32) << std::endl;
}

int main()
{
	int int_array[5] = {1, 2, 3, 4, 5};
	std::cout << "\nInt array with <print> function: " << std::endl;
	iter(int_array, 5, print);
	std::cout << "\nInt array with <next> function: " << std::endl;
	iter(int_array, 5, next);

	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "\nString array with <print> function: " << std::endl;
	iter(char_array, 5, print);
	std::cout << "\nString array with <upper> function: " << std::endl;
	iter(char_array, 5, upper);

	 Awesome tab2[5];
	 std::cout << "\nAwesome class with <print> function: " << std::endl;
	 iter(tab2, 5, print);

	return (0);
}
