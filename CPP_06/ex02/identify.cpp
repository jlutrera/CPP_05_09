#include "identify.hpp"

Base *generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base *p)
{
	std::cout << YELLOW << "Pointer   : " << RESET;
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << YELLOW << "Reference : " << RESET << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "dynamic_cast<A &> failed" << RESET << std::endl;
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << YELLOW << "Reference : " << RESET << "B" << std::endl;
		(void)b;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "dynamic_cast<B &> failed !" << RESET << std::endl;
	}
	
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << YELLOW << "Reference : " << RESET << "C" << std::endl;
		(void)c;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "dynamic_cast<C &> failed" << RESET << std::endl;
	}
}
