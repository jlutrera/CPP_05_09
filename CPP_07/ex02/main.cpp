#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

int main(int, char**)
{
	srand(time(NULL));

	std::cout << std::endl;
	std::cout << "------------Probamos constructores y copias------------" << std::endl;
    Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = rand() % 100;
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	std::cout << std::endl;
    Array<int> mirror (numbers);
	for (unsigned int i = 0; i < numbers.size(); i++)
    {
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
    }

	std::cout << std::endl;
    Array<int> mirror2 = numbers;
	for (unsigned int i = 0; i < mirror2.size(); i++)
    {
		std::cout << "mirror2[" << i << "] = " << mirror2[i] << std::endl;
    }

	std::cout << std::endl;
	std::cout << "---------Cambiamos elementos del array original----------" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = rand() % 100;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		std::cout << "number[" << i << "] = " << numbers[i] << std::endl;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < mirror.size(); i++)
	{
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < mirror2.size(); i++)
    {
		std::cout << "mirror2[" << i << "] = " << mirror2[i] << std::endl;
    }

	std::cout << std::endl;
	std::cout << "------------------Probamos  excepciones------------------" << std::endl;
	Array<char> test2;
	try
	{
		std::cout << "1. ";
		test2[0] = '3';
	}
	catch(const std::exception& e)
	{
		std::cerr << "The array is size = 0" << std::endl;
	}

    try
    {
		std::cout << "2. ";
        numbers[-2] = '0';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Negative index" << std::endl;
    }

    try
    {
		std::cout << "3. ";
        numbers[5] = '0';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Index out of bounds" << std::endl;
    }

	std::cout << std::endl;

	std::cout << "--------------Probamos con otros tipos de datos----------" << std::endl;
	Array<int> a = Array<int>(3);
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;

	std::cout << std::endl;
	Array<char> b = Array<char>(3);
	b[0] = 'a';
	b[1] = 'b';
	b[2] = 'c';
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;

	std::cout << std::endl;
	Array<char> c = Array<char>(b);
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;

	std::cout << std::endl;
	Array<std::string> str1 = Array<std::string>();
	Array<std::string> str2 = Array<std::string>(4);
	str2[0] = "how";
	str2[1] = "are";
	str2[2] = "you";
	str2[3] = "?";
	str1 = str2;
	for (int i = 0; i < 4; i++)
		std::cout << str1[i] << " ";
	std::cout << std::endl << "Size = " << str1.size() << std::endl;

	std::cout << std::endl;
	try
	{
		a[80];
		b[80];
		c[80];
	}
	catch (std::exception & exception)
	{
		std::cout << "\033[36m" << exception.what() << "\033[0m" << std::endl;
		return 0;
	}

	std::cout << std::endl;
	return 0;
}
