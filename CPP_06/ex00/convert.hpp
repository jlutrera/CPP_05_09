#ifndef CONVERT_HPP
# define CONVERT_HPP

# define FLT_MIN -3.40282e+38
# define FLT_MAX 3.40282e+38
# define DBL_MIN -1.79769e+308
# define DBL_MAX 1.79769e+308

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"

# include <iostream>
# include <climits>
# include <sstream>
# include <iomanip>

class Convert
{
public:
	Convert(std::string str);
	Convert(const Convert &copy);
	~Convert();
	Convert &operator=(const Convert &copy);

	std::string getType() const;
	char 		getChar() const;
	long double getNumber() const;
	std::string getStr() const;
	void 		display();

private:
	std::string _type;
	std::string _str;
	char 		_c;
	long double _ld;
	
	Convert();
	void 		isChar() const;
	void		isNumber() const;
	void 		isSpecial() const;
	void 		isImpossible() const;
	void 		detectLiteral();
};

#endif
