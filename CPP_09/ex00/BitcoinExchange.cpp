#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this == &copy)
		return (*this);
	this->_exchange = copy._exchange;
	this->_date = copy._date;
	this->_value = copy._value;
	this->_t = copy._t;
	return (*this);
}

void BitcoinExchange::checkFile(std::ifstream &fd, const char *name)
{
	fd.open(name);
	if (!fd.is_open())
	{
		std::cerr << RED << " Error : Can't open the file " << name << RESET << std::endl;
		exit(1);
	}
}

void BitcoinExchange::readFile(std::ifstream &fd, BitcoinExchange &exchange, const char &c)
{
	std::string line;
	getline(fd, line);
	while (getline(fd, line))
	{
		try
		{
			exchange.loadData(line, c);
			if (c == '|')
				exchange.calculate();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
	}
	fd.close();
}

void BitcoinExchange::calculate(void)
{
	std::map<std::string, float>::iterator it;

	it = _exchange.find(_date);
	if (it == _exchange.end())
	{
		it = _exchange.upper_bound(_date);
		if (it == _exchange.begin())
			throw std::invalid_argument(" Error : Invalid date");
		--it;
	}
	std::cout << " " << YELLOW << _date << RESET << " => ";
	std::cout << CYAN  << std::right << std::setw(7) << _value << RESET << " * ";
	std::cout << std::left << std::setw(7) << it->second << " = ";
	std::cout << GREEN << std::left << std::setw(11) << (_value * it->second) << RESET;
	std::cout << " [" << it->first << "] " << std::endl;
}

time_t BitcoinExchange::_loadDate(std::string &line)
{
	
	time_t today = std::time(0);
	std::tm *ltm = std::localtime(&today);
	int actualYear = ltm->tm_year + 1900;
	int daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	
	struct tm tm;
	int year, month, day;
	std::sscanf(line.c_str(), "%d-%d-%d", &year, &month, &day);
	//Bitcoin was created in 2009
	if (year > actualYear || year < 2009)
		throw std::invalid_argument(" Error : Invalid year value");
	tm.tm_year = year - 1900;
	if (month > 12 || month < 1)
		throw std::invalid_argument(" Error : Invalid month value");
	tm.tm_mon = month - 1;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysOfMonth[1] = 29;
	if ((day < 1 || day > daysOfMonth[month - 1]))
		throw std::invalid_argument(" Error : Invalid day value");
	tm.tm_mday = day;
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	time_t t = mktime(&tm);
	return (t);
}

float BitcoinExchange::_loadValue(std::string &line, const float &limit)
{
	float v;

	std::istringstream (line) >> v;
	if (v < 0)
		throw std::invalid_argument(" Error : Negative value");
	else if (v > limit)
		throw std::invalid_argument(" Error : Value greater than 1000");
	return (v);
}

void BitcoinExchange::loadData(std::string &line, const char &c)
{
	std::string st;
	std::string sv;
	time_t 		t;
	float  		v;
	float	 	limit;

	limit = (c == ',') ? FLT_MAX : 1000;
	st = line.substr(0, line.find(c));
	if (st.length() == 0 || st.length() == line.length())
		throw std::invalid_argument(" Error : Invalid line format");
	
	t = _loadDate(st);
	sv = line.substr(line.find(c) + 1);
	if (sv.length() == 0 || sv.length() == line.length())
		throw std::invalid_argument(" Error Invalid line format");
	
	v = _loadValue(sv, limit);
	if (c == ',')
		_exchange.insert(std::pair<std::string, float>(st, v));
	else
	{
		_date = st;
		_value = v;
		_t = t;
	}
}
