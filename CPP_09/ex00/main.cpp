#include "BitcoinExchange.hpp"

static void print_header( void )
{
	std::cout << "\n>>>>>>>>>>>>>>>>>>>> BITCOIN  EXCHANGE <<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << YELLOW << " Date given "  << RESET << " => ";
	std::cout << CYAN   << "  Value"   << RESET << " * ";
	std::cout << "Change " << " = ";
	std::cout << GREEN  << "Result"  << RESET;
	std::cout << "      [Date found]" << std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
}

int main(int argc, char **argv)
{
	std::ifstream 	fd_data;
	std::ifstream 	fd_input;
	BitcoinExchange	exchange;

	// Check number of arguments
	if (argc != 2)
	{
		std::cerr << RED << " Error : Usage ./btc <filename>" << RESET << std::endl;
		exit(1);
	}

	// Check if file "data.csv" exists and can be opened
	exchange.checkFile(fd_data, "data.csv");

	// Check if file, which name is in argv[1], exists and can be opened
	exchange.checkFile(fd_input, argv[1]);

	// Read data from file "data.csv" and store it in "_exchange"
	// Values in file "data.csv" are separated by commas and can be any positive float number
	exchange.readFile(fd_data, exchange, ',');
	
	print_header();
	// Read data from file, which name is in argv[1], and
	// calculate the value of the bitcoin at the date specified in the file
	// Values in file, which name is in argv[1], are separated by pipes and
	// can be any positive float number less than 1000
	exchange.readFile(fd_input, exchange, '|');
	
	return (0);
}
