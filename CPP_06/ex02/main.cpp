#include "identify.hpp"

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n>>-------" << " TEST " << i + 1 << " -------<<" << std::endl;
		Base *base = generate();
		identify(base);
		if (base)
		{	
			identify(*base);
			delete base;
		}
		else
		{
			std::cout << YELLOW << "Reference : " << RESET;
			std::cout << RED << "The pointer is NULL" << RESET << std::endl;
		}
	}
	return (0);
}
