#include "BitcoinExchange.hpp"

int main()
{
	BitcoinExchange btc;

	
	
	btc.setData("data");
	btc.setData("data", "date");
	btc.setData("data", "date", "time");
	btc.setData("data", "date", "time", "price");
	btc.setData("data", "date", "time", "price", "volume");
	btc.setData("data", "date", "time", "price", "volume", "marketcap");
	btc.setData("data", "date", "time", "price", "volume", "marketcap", "coin");
	btc.printData();
	return (0);
}