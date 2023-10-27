#include "Array.hpp"

int main()
{
	Array<int> int_array(5);
	Array<std::string> string_array(5);

	for (unsigned int i = 0; i < int_array.size(); i++)
		int_array[i] = i + 1;
	for (unsigned int i = 0; i < string_array.size(); i++)
		string_array[i] = std::to_string(i + 1);

	std::cout << "int_array: " << std::endl;
	for (unsigned int i = 0; i < int_array.size(); i++)
		std::cout << int_array[i] << std::endl;
	std::cout << std::endl;
	std::cout << "string_array: " << std::endl;
	for (unsigned int i = 0; i < string_array.size(); i++)
		std::cout << string_array[i] << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "int_array[5]: " << int_array[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "string_array[5]: " << string_array[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
