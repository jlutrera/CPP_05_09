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
	this->_data = copy._data;
	this->_date = copy._date;
	this->_time = copy._time;
	this->_price = copy._price;
	this->_volume = copy._volume;
	this->_marketcap = copy._marketcap;
	this->_coin = copy._coin;
	return (*this);
}

void	BitcoinExchange::setData(std::string data)
{
	this->_data = data;
}

void	BitcoinExchange::setData(std::string data, std::string date)
{
	this->_data = data;
	this->_date = date;
}

void	BitcoinExchange::setData(std::string data, std::string date, std::string time)
{
	this->_data = data;
	this->_date = date;
	this->_time = time;
}

void	BitcoinExchange::setData(std::string data, std::string date, std::string time, std::string price)
{
	this->_data = data;
	this->_date = date;
	this->_time = time;
	this->_price = price;
}

void	BitcoinExchange::setData(std::string data, std::string date, std::string time, std::string price, std::string volume)
{
	this->_data = data;
	this->_date = date;
	this->_time = time;
	this->_price = price;
	this->_volume = volume;
}

void	BitcoinExchange::setData(std::string data, std::string date, std::string time, std::string price, std::string volume, std::string marketcap)
{
	this->_data = data;
	this->_date = date;
	this->_time = time;
	this->_price = price;
	this->_volume = volume;
	this->_marketcap = marketcap;
}

void	BitcoinExchange::setData(std::string data, std::string date, std::string time, std::string price, std::string volume, std::string marketcap, std::string coin)
{
	this->_data = data;
	this->_date = date;
	this->_time = time;
	this->_price = price;
	this->_volume = volume;
	this->_marketcap = marketcap;
	this->_coin = coin;
}

std::string	BitcoinExchange::getData() const
{
	return (this->_data);
}

std::string	BitcoinExchange::getDate() const
{
	return (this->_date);
}

std::string	BitcoinExchange::getTime() const
{
	return (this->_time);
}

std::string	BitcoinExchange::getPrice() const
{
	return (this->_price);
}

std::string	BitcoinExchange::getVolume() const
{
	return (this->_volume);
}

std::string	BitcoinExchange::getMarketcap() const
{
	return (this->_marketcap);
}

std::string	BitcoinExchange::getCoin() const
{
	return (this->_coin);
}

void	BitcoinExchange::printData() const
{
	std::cout << "Data: " << this->_data << std::endl;
	std::cout << "Date: " << this->_date << std::endl;
	std::cout << "Time: " << this->_time << std::endl;
	std::cout << "Price: " << this->_price << std::endl;
	std::cout << "Volume: " << this->_volume << std::endl;
	std::cout << "Marketcap: " << this->_marketcap << std::endl;
	std::cout << "Coin: " << this->_coin << std::endl;
}

void BitcoinExchange::run(std::string line)	const
{

}