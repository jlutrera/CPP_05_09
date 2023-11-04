#include "Convert.hpp"

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

std::string Convert::getStr() const
{
	return (_str);
}

void Convert::detectLiteral( void )
{
	std::string str = _str;
	_c = str[0];
	if (str[str.length() -1] == 'f' && isdigit(str[0]) &&
		_ld <= static_cast<long double>(FLT_MAX) &&
		_ld >= static_cast<long double>(FLT_MIN) )
	{
		_type = "float";
		str = str.substr(0, str.length() - 1);
		std::istringstream(str) >> _ld;
	}

	else
	{
		std::istringstream(str) >> _ld;

		if ( !str.compare("nan")  || !str.compare("nanf")  ||
			!str.compare("inf")  || !str.compare("inff")  ||
		 	!str.compare("+inf") || !str.compare("+inff") ||
	  	 	!str.compare("-inf") || !str.compare("-inff") )
		_type = "special";

		else if ( !isdigit(str[0])  && str[0] != '+' && str[0] != '-' )
			_type = "char";

		else if ((isdigit(str[0]) || str[0] == '-' || str[0] == '+' ) &&
			 	  str.find('.') == std::string::npos &&
				  _ld <= static_cast<long double>(INT_MAX) &&
				  _ld >= static_cast<long double>(INT_MIN) &&
				  _ld == static_cast<int>(_ld) )
			_type = "int";

		else if ( _ld <= static_cast<long double>(DBL_MAX) &&
				  _ld >= static_cast<long double>(DBL_MIN) )
			_type = "double";

		else
			_type = "impossible";
	}

	std::cout << ">>---- Detected a " << GREEN << _type << RESET;
	std::cout << " literal ----<<" << std::endl;}

void Convert::isChar( void ) const
{
	char c = _c;

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

void Convert::isNumber( void ) const
{
	long double d = this->_ld;

	//printing char literal
	std::cout << "  char   : ";
	if (d != static_cast<int>(d) || d < 32 || d > 126)
		std::cout << RED << "Non displayable" << RESET << std::endl;
	else
		std::cout << "'" << CYAN << static_cast<char>(d) << RESET << "'" << std::endl;
	
	//printing int literal
	std::cout << "  int    : ";
	if (d > static_cast<long double>(INT_MAX) || d < static_cast<long double>(INT_MIN) ||
		d != static_cast<int>(d))
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << CYAN << static_cast<int>(d) << RESET << std::endl;	

	//printing float literal
	std::cout << "  float  : ";
	if (d >  static_cast<long double>(FLT_MAX) || d < static_cast<long double>(FLT_MIN))
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << CYAN << d << "f" << RESET << std::endl;

	//printing double literal
	std::cout << "  double : ";
	if (d >  static_cast<long double>(DBL_MAX) || d < static_cast<long double>(DBL_MIN))
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << CYAN << d << RESET << std::endl;
}

void Convert::isSpecial( void ) const
{
	std::string str = this->_str;
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

void Convert::isImpossible() const
{
	std::cout << "  char   : " << RED << "Non displayable" << RESET << std::endl;
	std::cout << "  int    : " << RED << "Impossible" << RESET << std::endl;
	std::cout << "  float  : " << RED << "Impossible" << RESET << std::endl;
	std::cout << "  double : " << RED << "Impossible" << RESET << std::endl;
}

void Convert::display(void)
{
	std::string t[6] = {"char", "int", "float", "double", "special", "impossible"};

	detectLiteral();
	
	int i = 0;
	while (i < 5 && getType().compare(t[i]) != 0)
		i++;
	
	switch (i)
	{
		case 0:  isChar();
				 break;
		case 1:  isNumber();
				 break;
		case 2:  isNumber();
				 break;
		case 3:  isNumber();
				 break;
		case 4:  isSpecial();
				 break;
		default: isImpossible();
			  	 break;
	}
}
