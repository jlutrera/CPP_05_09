#include "iter.hpp"

class Awesome
{
	public:
		Awesome():_n(42){}
		int get() const
		{
			return _n;
		}
	private:
		int _n;
};

std::ostream & operator << (std::ostream & o, const Awesome & rhs)
{
	o << rhs.get();
	return o;
}

int main()
{
	int int_array[5] = {1, 2, 3, 4, 5};
	std::cout << "\nint_array with <print> function: " << std::endl;
	iter(int_array, 5, print);
	std::cout << "\nint_array with <next> function: " << std::endl;
	iter(int_array, 5, next);

	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "\nstring_array with <print> function: " << std::endl;
	iter(char_array, 5, print);
	std::cout << "\nstring_array with <upper> function: " << std::endl;
	iter(char_array, 5, upper);

	 Awesome tab2[5];
	 std::cout << "\nAwesome array with <print> function: " << std::endl;
	 iter(tab2, 5, print);

	return (0);
}
