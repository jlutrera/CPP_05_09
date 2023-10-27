#include "iter.hpp"
#include <iostream>

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

	return (0);
}
