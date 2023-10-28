#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 5

int main(int, char**)
{
	srand(time(NULL));

	std::cout << std::endl;
	std::cout << "------------Probamos constructores y copias------------" << std::endl;
    Array<int> numbers(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	std::cout << std::endl;
    Array<int> mirror = numbers;
	for (int i = 0; i < MAX_VAL; i++)
    {
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
    }

	std::cout << std::endl;
	std::cout << "---------Cambiamos elementos del array <numbers>---------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "------------------Probamos  excepciones------------------" << std::endl;
	Array<int> test2;
	try
	{
		std::cout << "1. ";
		test2[0] = 3;
	}
	catch(const std::exception& e)
	{
		std::cerr << "The array is size = 0" << std::endl;
	}

    try
    {
		std::cout << "2. ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Negative index" << std::endl;
    }

    try
    {
		std::cout << "3. ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Index out of bounds" << std::endl;
    }

	std::cout << std::endl;
	return 0;
}