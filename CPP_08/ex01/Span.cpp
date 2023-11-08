#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &copy)
{
	if (this == &copy)
		return (*this);
	_N = copy._N;
	_V = copy._V;
	return (*this);
}

void Span::addNumber(int n)
{
	if (_V.size() == _N)
		throw FullSpanException();

	_V.push_back(n);
}

void Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	if (_V.size() + std::distance(begin, end) > _N)
		throw FullSpanException();

	_V.insert(_V.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_V.size() <= 1)
		throw NoSpanException();
	
	std::vector<int> tmp(_V);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		int aux = *(it + 1) - *it;
		if (aux < min)
			min = aux;
	}
	return (min);
}

int Span::longestSpan()
{
	if (_V.size() <= 1)
		throw NoSpanException();

	std::vector<int> tmp(_V);
	int max = *std::max_element(tmp.begin(), tmp.end());
	int min = *std::min_element(tmp.begin(), tmp.end());
	return (max - min);
}

const char *Span::FullSpanException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Span is empty or contains only one element");
}
