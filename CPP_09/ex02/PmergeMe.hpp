#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>

template <typename T>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(T const &value);
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);

private:
	
};

#endif