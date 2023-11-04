#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(11);
	sp.addNumber(9);
	sp.addNumber(17);
	std::cout << "\n******** Test 1: 5, 3, 17, 9, 11 *******" << std::endl;
	std::cout << "Shortest Span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span  = " << sp.longestSpan() << std::endl;

	Span sp2 = Span(10000);
	std::vector<int> v(10000);
	std::generate(v.begin(), v.end(), rand);
	sp2.addNumber(v.begin(), v.end());
	std::cout << "\n******* Test 2: 10,000 elements *******" << std::endl;
	std::cout << "Shortest Span = " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span  = " << sp2.longestSpan() << std::endl;

	Span sp21 = Span(1000000);
	std::vector<int> v1(1000000);
	std::generate(v1.begin(), v1.end(), rand);
	sp21.addNumber(v1.begin(), v1.end());
	std::cout << "\n******* Test 3: 1,000,000 elements *******" << std::endl;
	std::cout << "Shortest Span = " << sp21.shortestSpan() << std::endl;
	std::cout << "Longest Span  = " << sp21.longestSpan() << std::endl;

	std::cout << "\n******* Test 4. Exceptions Test *******" << std::endl;
	
	Span sp3 = sp2;
	try
	{
		std::cout << "4.1. AddNumber(1) to a full Span" << std::endl;
		sp3.addNumber(v.begin(), v.end());
		sp3.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span sp4 = Span(1);
	try
	{
		std::cout << "4.2. ShortestSpan() on a Span with 1 element" << std::endl;
		sp4.shortestSpan();
		sp4.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "4.3. LongestSpan() on a Span with 1 element" << std::endl;
		sp4.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span sp5 = Span();
	try
	{
		std::cout << "4.4. ShortestSpan() on a Span with 0 elements" << std::endl;
		sp5.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "4.5. LongestSpan() on a Span with 0 elements" << std::endl;
		sp5.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
