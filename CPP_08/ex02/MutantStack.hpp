#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET			"\033[0m"
# define YELLOW			"\033[33m"
# define CYAN			"\033[36m"

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		virtual ~MutantStack() {}
		MutantStack &operator=(const MutantStack &copy)
		{
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin()
		{
			return (std::stack<T>::c.begin());
		}
		iterator	end()
		{
			return (std::stack<T>::c.end());
		}
};

#endif
