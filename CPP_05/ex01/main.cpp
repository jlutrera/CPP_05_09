#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	pepe("Pepe", 150);
	Bureaucrat	jose("Jose", 5);

	std::cout << "<pepe> named " << pepe << std::endl;
	std::cout << "<jose> named " << jose << std::endl;

	jose = pepe;

	try
	{
		pepe.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "<pepe> named " << pepe << std::endl;
	std::cout << "<jose> named " << jose << std::endl;

	try
	{
		pepe.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << pepe << std::endl;

	try
	{
		pepe.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	jose.incrementGrade();

	std::cout << "<Pepe> named " << pepe << std::endl;
	std::cout << "<jose> named " << jose << std::endl;

	try
	{
		Bureaucrat	carlos("Carlos", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	carlos("Carlos", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
