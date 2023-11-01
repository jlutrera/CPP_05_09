#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <ctime>
# include <stdexcept>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iomanip>

# define FLT_MAX 3.40282e+38

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define CYAN			"\033[36m"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void	calculate(void);
		void	loadData(std::string &line, const char &c);
		void 	checkFile(std::ifstream &fd, const char *name);
		void 	readFile(std::ifstream &fd, BitcoinExchange &exchange, const char &c);
	private:
		std::map<std::string, float> _exchange;
		std::string 			_date;
		float 					_value;
		time_t 					_t;
		time_t 	_loadDate(std::string &line);
		float 	_loadValue(std::string &line, const float &limit);
};

#endif
