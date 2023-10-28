#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <iterator>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <exception>
# include <ctime>
# include <cstdlib>
# include <cmath>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void		setData(std::string data);
		void		setData(std::string data, std::string date);
		void		setData(std::string data, std::string date, std::string time);
		void		setData(std::string data, std::string date, std::string time, std::string price);
		void		setData(std::string data, std::string date, std::string time, std::string price, std::string volume);
		void		setData(std::string data, std::string date, std::string time, std::string price, std::string volume, std::string marketcap);
		void		setData(std::string data, std::string date, std::string time, std::string price, std::string volume, std::string marketcap, std::string coin);

		std::string	getData() const;
		std::string	getDate() const;
		std::string	getTime() const;
		std::string	getPrice() const;
		std::string	getVolume() const;
		std::string	getMarketcap() const;
		std::string	getCoin() const;

		void		printData() const;
		void		printData(std::string coin) const;
		void		run(std::string line) const;

	private:
		std::string	_data;
		std::string	_date;
		std::string	_time;
		std::string	_price;
		std::string	_volume;
		std::string	_marketcap;
		std::string	_coin;
};

#endif