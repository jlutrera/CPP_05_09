#include "RPN.hpp"

int main(int argc, char **argv)
{
	//podemos visualizar la operación en formato prefix con el flag --prefix antes de la expresión RPN
	if ((argc != 3 && argc != 2) ||
		(argc == 3 && std::string(argv[1]) != "--prefix") ||
		(argc == 2 && std::string(argv[1]) == "--prefix"))
	{
		std::cout << "Error : Usage... ./rpn [--prefix] <expression>" << std::endl;
		return (1);
	}
	int pren =  (std::string(argv[1]) == "--prefix") + 1;

	try
	{
		RPN rpn;
		rpn.process(argv[pren]);
		rpn.print(pren);
		return (0);
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}
