#include "identify.hpp"

Base *generate(void)
{
	int i = rand() % 4;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
		{
			std::cout << ">> None  class  called  <<" << std::endl;
			return (NULL);
		}
	}
}

void identify(Base *p)
{
	std::cout << YELLOW << "Pointer   : " << RESET;
	if (dynamic_cast<A *>(p))
		std::cout << CYAN << "A" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << CYAN << "B" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << CYAN << "C" << RESET << std::endl;
	else
		std::cout << RED << "Unknown" << RESET << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << YELLOW << "Reference : " << CYAN << "A" << RESET << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "            dynamic_cast<A &> failed" << RESET << std::endl;
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << YELLOW << "Reference : " << CYAN << "B" << RESET << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "            dynamic_cast<B &> failed !" << RESET << std::endl;
	}
	
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << YELLOW << "Reference : " << CYAN << "C" << RESET << std::endl;
		(void)c;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "             dynamic_cast<C &> failed" << RESET << std::endl;
	}
}
