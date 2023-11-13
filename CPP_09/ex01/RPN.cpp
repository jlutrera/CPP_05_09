#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		this->_stack = copy._stack;
		this->_stack_str = copy._stack_str;
	}	
	return (*this);
}

void RPN::push(int value)
{
	this->_stack.push(value);
}

int RPN::pop()
{
	int value = this->_stack.top();
	this->_stack.pop();
	return (value);
}

void RPN::push_str(std::string value)
{
	this->_stack_str.push(value);
}

std::string RPN::pop_str()
{
	std::string value = this->_stack_str.top();
	this->_stack_str.pop();
	return (value);
}

int RPN::getSize() const
{
	return (this->_stack.size());
}

int RPN::getSize2() const
{
	return (this->_stack_str.size());
}

void RPN::operation(char c)
{
	if (_stack.size() < 2)
		throw std::invalid_argument( "Error : Invalid expression");
	
	int b = pop();
	int a = pop();
	switch (c)
	{
		case '+': push(a + b);
				  break;
		case '-': push(a - b);
				  break;
		case '*': push(a * b);
				  break;
		case '/': push(a / b);
				  break;
		default:  throw std::invalid_argument( "Error : Invalid expression");
				  break;
	}

	std::string str_b = pop_str();
	std::string str_a = pop_str();
	push_str("(" + str_a + " " + c + " " + str_b + ")");
}

void RPN::process(char *c)
{
	int i = -1;
	while (c[++i])
	{
		//Si el carácter es un dígito, lo añadimos a la pila de enteros y a la pila de strings
		if (isdigit(c[i]))
		{
			push(c[i] -'0');
			push_str(std::string(1, c[i]));
		}
		//Si no , el carácter es un operador, y realizamos la operación correspondiente
		else if (c[i] != ' ')
			operation(c[i]);
	}
}

void RPN::print(int pren)
{
	//Si la pila de enteros no tiene un único elemento, lanzamos una excepción
	if (getSize() != 1)
		throw std::invalid_argument( "Error : Invalid expression");
	std::string prefix = pop_str();
	//Si la expresión es en formato prefix, eliminamos los paréntesis del principio y del final
	if (prefix[0] == '(')
		prefix = prefix.substr(1, prefix.size() - 2);
	//Si el flag --prefix se activó, mostramos la expresión prefix y el resultado
	if (pren == 2)
		std::cout << prefix << " = " << pop() << std::endl;
	//y si no, mostramos sólo el resultado
	else
		std::cout << "Result = " << pop() << std::endl;
}
