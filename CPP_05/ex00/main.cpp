#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "*****************************" << std::endl;
	std::cout << "****** BUREAUCRAT TEST ******" << std::endl;
	std::cout << "*****************************" << std::endl;

	std::cout << "Creating bureaucrats:" << std::endl;
	Bureaucrat	pepe("Pepe", 140);
	Bureaucrat	jose("Jose", 5);
	std::cout << pepe << std::endl;
	std::cout << jose << std::endl;

	std::cout << "Incrementing and decrementing bureaucrats:" << std::endl << std::endl;
	jose = pepe;
	pepe.incrementGrade();
	std::cout << pepe << std::endl;
	std::cout << jose << std::endl;
	jose.decrementGrade();
	std::cout << pepe << std::endl;
	std::cout << jose << std::endl;
	pepe.decrementGrade();
	jose.incrementGrade();
	std::cout << pepe << std::endl;
	std::cout << jose << std::endl;

	std::cout << "Trying to create bureaucrats with invalid grades:" << std::endl;
	Bureaucrat	carlos("Carlos", 0);
	Bureaucrat	carlos2("Carlos2", 151);
	std::cout << carlos << std::endl;
	std::cout << carlos2 << std::endl;
	
	std::cout << "Destroying bureaucrats:" << std::endl;
	return (0);
}
