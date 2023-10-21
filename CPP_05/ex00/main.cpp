#include "Bureaucrat.hpp"

int	main(void)
{
	BureauCrat	bureaucrat("bureaucrat", 150);

	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	try
	{
		BureauCrat	bureaucrat2("bureaucrat2", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		BureauCrat	bureaucrat2("bureaucrat2", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}