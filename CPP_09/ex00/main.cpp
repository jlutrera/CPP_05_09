#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: btc <filename>" << std::endl;
		exit(1);
	}
	std::ifstream fd;
	fd.open(argv[1]);

	if (!fd.is_open())
	{
		std::cout << "Error opening file!" << std::endl;
		exit(1);
	}

	BitcoinExchange exchange;
	std::string line;
	while (getline(fd, line))
	{
		exchange.run(line);
	}
	fd.close();
}