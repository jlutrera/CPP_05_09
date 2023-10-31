#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(T const &value);
	PmergeMe(PmergeMe const &src);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	T const &getValue() const;
	void setValue(T const &value);

private:
	T _value;
};

#endif