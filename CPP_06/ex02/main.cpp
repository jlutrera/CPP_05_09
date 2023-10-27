#include "identify.hpp"

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n>>------" << CYAN << "TEST " << i + 1 << RESET << " ------<<" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}
