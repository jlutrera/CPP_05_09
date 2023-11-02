#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
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
	_n = copy._n;
	_v = copy._v;
	return (*this);
}

void Span::addNumber(unsigned int n)
{
	if (_v.size() == _n)
		throw FullSpanException();
	_v.push_back(n);
}

void Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw FullSpanException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::FullSpanException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Span is empty or contains only one element");
}
