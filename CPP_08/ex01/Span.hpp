#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_v;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);

		void	addNumber(unsigned int n);
		void	addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
