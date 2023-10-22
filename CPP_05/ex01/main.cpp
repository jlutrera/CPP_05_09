#include "Bureaucrat.hpp"

int	main(void)
{
	int i = 4;

	Form		f("Form", false, 1, 6);
	Bureaucrat	b("Camile", 3);
	while (i-- > -1)
	{
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		try
		{
			b.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
