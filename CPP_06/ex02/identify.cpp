#include "identify.hpp"

Base::~Base(void) {}

Base *generate(void)
{
	int random = rand() % 4;
	Base *base;

	std::cout << "Created  : ";
	switch (random)
	{
		case 0:	std::cout << "A" << std::endl;
				base = new A;
				break;
		case 1:	std::cout << "B" << std::endl;
				base = new B;
				break;
		case 2:	std::cout << "C" << std::endl;
				base = new C;
				break;
		default:std::cout << "NULL" << std::endl;
				base = NULL;
				break;
	}
	return (base);
}

void identify(Base *p)
{
	std::cout << "Pointer  : ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Reference: ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e){}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (std::exception &e){}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (std::exception &e){}
}