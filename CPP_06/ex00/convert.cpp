#include "convert.hpp"
#include "colors.hpp"

Convert::Convert()
{
}

Convert::Convert(std::string str) : _type(""), _str(str), _c(0), _ld(0)
{
}

Convert::Convert(const Convert &copy)
{
	*this = copy;
}

Convert::~Convert()
{
}

Convert &Convert::operator=(const Convert &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		_str = copy._str;
		_c = copy._c;
		_ld = copy._ld;
	}
	return (*this);
}

std::string Convert::getType() const
{
	return (_type);
}

char Convert::getChar() const
{
	return (_c);
}

long double Convert::getNumber() const
{
	return (_ld);
}

void Convert::DetectLiteral(std::string str)
{
	if ( !str.compare("nan")  || !str.compare("nanf")  ||
		 !str.compare("inf")  || !str.compare("inff")  ||
		 !str.compare("+inf") || !str.compare("+inff") ||
	  	 !str.compare("-inf") || !str.compare("-inff") )
		_type = "special";
	else if (!isdigit(str[0])  && str[0] != '+' && str[0] != '-')
	{
		_type = "char";
		_c = str[0];
	}
	else if (str.find('.') != std::string::npos && str.find('f') != std::string::npos)
	{
		_type = "float";
		std::istringstream(str) >> _ld;
	} 
	else if ((str.find('.') != std::string::npos &&
			  str.find('f') == std::string::npos) ||
			( isdigit(str[0]) || str[0] == '-' || str[0] == '+'))
	{
		_type = "double";
		std::istringstream(str) >> _ld;
		if (_ld <= static_cast<long double>(INT_MAX) && _ld >= static_cast<long double>(INT_MIN) && _ld == static_cast<int>(_ld))
			_type = "int";
	}
	else
		_type = "impossible";
	std::cout << YELLOW << ">>---- Detected a " << GREEN << _type;
	std::cout << YELLOW <<" literal ----<<" << RESET << std::endl;}

void Convert::IsChar(char c)
{
	//printing char literal
	std::cout << "  char   : ";
	if (c < 32 || c > 126)
		std::cout << RED << "Non displayable" << RESET << std::endl;
	else
		std::cout << "'" << CYAN << c << RESET << "'" << std::endl;

	//printing int literal
	std::cout << "  int    : " << CYAN << static_cast<int>(c) << RESET << std::endl;

	//printing float literal
	std::cout << "  float  : " << CYAN <<  static_cast<float>(c);
	if (_str.find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << "f" << RESET << std::endl;

	//printing double literal
	std::cout << "  double : " << CYAN <<  static_cast<double>(c);
	if (_str.find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << RESET << std::endl;
}

void Convert::IsNumber(long double d)
{
	//printing char literal
	std::cout << "  char   : ";
	if (d < 32 || d > 126)
		std::cout << RED << "Non displayable" << RESET << std::endl;
	else
		std::cout << "'" << CYAN << static_cast<char>(d) << RESET << "'" << std::endl;
	
	//printing int literal
	std::cout << "  int    : ";
	if (d > static_cast<long double>(INT_MAX) || d < static_cast<long double>(INT_MIN) || d != static_cast<int>(d))
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << CYAN << static_cast<int>(d) << RESET << std::endl;	

	//printing float literal
	std::cout << "  float  : ";
	if (d >  static_cast<long double>(FLT_MAX) || d <  static_cast<long double>(FLT_MIN))
		std::cout << RED << "impossible" << RESET << std::endl;
	else
	{
		std::cout << CYAN << static_cast<float>(d);
		if (_str.find('.') == std::string::npos)
			std::cout << ".0";
		std::cout << "f" << RESET << std::endl;
	}

	//printing double literal
	std::cout << "  double : ";
	if (d >  static_cast<long double>(DBL_MAX) || d <  static_cast<long double>(DBL_MIN))
		std::cout << RED << "impossible" << RESET << std::endl;
	else
	{
		std::cout << CYAN << d;
		if (_str.find('.') == std::string::npos)
			std::cout << ".0";
		std::cout << RESET << std::endl;
	}
}

void Convert::IsSpecial(std::string str)
{
	std::cout << "  char   : " << RED << "Non displayable" << RESET << std::endl;
	std::cout << "  int    : " << RED << "Impossible" << RESET << std::endl;

	//printing float literal
	std::cout << "  float  : " << CYAN;
	if (!str.compare("nan") || !str.compare("nanf"))
		std::cout << "nanf";
	else if (!str.compare("inf") || !str.compare("inff"))
		std::cout << "inff";
	else if (!str.compare("+inf") || !str.compare("+inff"))
		std::cout << "+inff";
	else if (!str.compare("-inf") || !str.compare("-inff"))
		std::cout << "-inff";
	std::cout << RESET << std::endl;

	//printing double literal
	std::cout << "  double : " << CYAN;
	if (!str.compare("nan") || !str.compare("nanf"))
		std::cout << "nan";
	else if (!str.compare("inf") || !str.compare("inff"))
		std::cout << "inf";
	else if (!str.compare("+inf") || !str.compare("+inff"))
		std::cout << "+inf";
	else if (!str.compare("-inf") || !str.compare("-inff"))
		std::cout << "-inf";
	std::cout << RESET << std::endl;
}

void Convert::IsImpossible()
{
	std::cout << "  char   : " << RED << "Non displayable" << RESET << std::endl;
	std::cout << "  int    : " << RED << "Impossible" << RESET << std::endl;
	std::cout << "  float  : " << RED << "Impossible" << RESET << std::endl;
	std::cout << "  double : " << RED << "Impossible" << RESET << std::endl;
}

void Convert::display(std::string str)
{
	if (getType() == "char")
		IsChar(getChar());
	else if (getType() == "double" ||
			 getType() == "int" ||
			 getType() == "float")
		IsNumber(getNumber());
	else if (getType() == "special")
		IsSpecial(str);
	else
		IsImpossible();
}
