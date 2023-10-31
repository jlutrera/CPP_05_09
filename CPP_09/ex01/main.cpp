#include "RPN.hpp"

int main(int argc, char **argv)
{
	int pren;
	//podemos visualizar la operación en formato prefix con el flag --prefix antes de la expresión RPN
	if ((argc != 3 && argc != 2) ||
		(argc == 3 && std::string(argv[1]) != "--prefix"))
	{
		std::cout << "Error : Usage... ./rpn [--prefix] <expression>" << std::endl;
		return (1);
	}
	pren =  (std::string(argv[1]) == "--prefix") + 1;

	int i = 0;
	RPN rpn;
	const std::string digits = "0123456789";
	const std::string operators = "+-*/";
	const std::string all_simbols = "0123456789+-*/ ";

	try
	{
		//Recorremos el argumento carácter a carácter
		while (argv[pren][i])
		{
			//Si el carácter no es un dígito ni un operador ni un espacio, lanzamos una excepción
			if (all_simbols.find(argv[pren][i]) == std::string::npos ||
			   (argv[pren][i] != ' ' && argv[pren][i + 1] != '\0' && argv[pren][i + 1] != ' '))
				throw std::invalid_argument( "Error : Invalid expression");
			
			if (argv[pren][i] != ' ')
			{
				//Si el carácter es un dígito, lo añadimos a la pila de enteros y a la pila de strings
				if (digits.find(argv[pren][i]) != std::string::npos)
				{
					rpn.push(argv[pren][i] -'0');
					rpn.push_str(std::string(1, argv[pren][i]));
				}
				//Si no , el carácter es un operador, y realizamos la operación correspondiente
				else
					rpn.operation(argv[pren][i]);  
			}
			i++;
		}
		//Si la pila de enteros no tiene un único elemento, lanzamos una excepción
		if (rpn.getSize() != 1)
			throw std::invalid_argument( "Error : Invalid expression");
		std::string prefix = rpn.pop_str();
		//Si la expresión es en formato prefix, eliminamos los paréntesis del principio y del final
		if (prefix[0] == '(')
			prefix = prefix.substr(1, prefix.size() - 2);
		//Si el flag --prefix se activó, mostramos la expresión prefix y el resultado
		if (pren == 2)
			std::cout << prefix << " = " << rpn.pop() << std::endl;
		//y si no, mostramos sólo el resultado
		else
			std::cout << "Result = " << rpn.pop() << std::endl;
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}