#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <sys/time.h>
#include <list>
#include <vector>

class AList
{
public:
	AList();
	AList(AList const &src);
	~AList();
	AList &operator=(AList const &rhs);

	void 	push_back(int n);
	double	sortList();
 	void	printList(std::string msg);

private:
	std::list<int>	_lst;
	std::list<int> 	mergeList(std::list<int> &left, std::list<int> &right);
	std::list<int> 	mergeSortList(std::list<int> &input);
};

class AVector
{
public:
	AVector();
	AVector(AVector const &src);
	~AVector();
	AVector &operator=(AVector const &rhs);

	void 	push_back(int n);
	double	sortVector();
	void	printVector(std::string msg);

private:
	std::vector<int>	_v;
	void	mergeSortVector(std::vector<int> &arr, int l, int r);
	void	mergeVector(std::vector<int>& arr, int l, int m, int r);
};

#endif
