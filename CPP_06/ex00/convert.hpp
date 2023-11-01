#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <climits>
# include <sstream>
# include <iomanip>

# define FLT_MIN -3.40282e+38
# define FLT_MAX 3.40282e+38
# define DBL_MIN -1.79769e+308
# define DBL_MAX 1.79769e+308

class Convert
{
public:
	Convert();
	Convert(std::string str);
	Convert(const Convert &copy);
	~Convert();
	Convert &operator=(const Convert &copy);

	void IsNumber(long double d);
	void IsSpecial(std::string str);
	void IsImpossible();
	void DetectLiteral(std::string str);
	std::string getType() const;
	char getChar() const;
	long double getNumber() const;
	void IsChar(char c);
	void display(std::string str);

private:
	std::string _type;
	std::string _str;
	char _c;
	long double _ld;
};

#endif
