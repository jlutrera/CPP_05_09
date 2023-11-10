#include "PmergeMe.hpp"

double	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

//************ CLASE MERGELIST ************//

AList::AList() : _lst()
{
}

AList::AList(AList const &src)
{
	*this = src;
}

AList::~AList()
{
}

AList &AList::operator=(AList const &rhs)
{
	if (this != &rhs)
		_lst = rhs._lst;
	return (*this);
}

std::list<int>	AList::mergeList(std::list<int> &left, std::list<int> &right)
{
	std::list<int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.pop_front();
        }
		else
		{
            result.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty())
	{
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

// Recursive function to perform merge sort on a list
std::list<int> AList::mergeSortList(std::list<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::list<int> left, right;
    int middle = input.size() / 2;
    int count = 0;

    for (std::list<int>::iterator it = input.begin(); it != input.end(); ++it)
	{
        if (count++ < middle)
			left.push_back(*it);
        else
			right.push_back(*it);
        
    }

    left = mergeSortList(left);
    right = mergeSortList(right);

    return mergeList(left, right);
}

void	AList::printList( std::string msg )
{
	std::list<int>::iterator it = _lst.begin();

	std::cout << msg;
	while (it != _lst.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

double AList::sortList()
{
	double start = ft_get_time();
	_lst = mergeSortList(_lst);
	double end = ft_get_time();
	return (end - start);
}

void AList::push_back(int n)
{
	_lst.push_back(n);
}

//************ CLASE MERGEVECTOR ************//

AVector::AVector() : _v()
{
}

AVector::AVector(AVector const &src)
{
	*this = src;
}

AVector::~AVector()
{
}

AVector &AVector::operator=(AVector const &rhs)
{
	if (this != &rhs)
		_v = rhs._v;
	return (*this);
}

// Merge two subarrays of vector arr[]
// First subarray is arr[l..m], second subarray is arr[m+1..r]
void	AVector::mergeVector(std::vector<int>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
            arr[k++] = L[i++];
		else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive function to perform merge sort on the vector
void AVector::mergeSortVector(std::vector<int> &arr, int l, int r)
{
    if (l < r)
	{
        int m = l + (r - l) / 2;
        mergeSortVector(arr, l, m);
        mergeSortVector(arr, m + 1, r);
        mergeVector(arr, l, m, r);
    }
}

void	AVector::printVector(std::string msg)
{
	std::vector<int>::iterator it = _v.begin();

	std::cout << msg;
	while (it != _v.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

double AVector::sortVector()
{
	double start = ft_get_time();
	mergeSortVector(_v, 0, _v.size() - 1);
	double end = ft_get_time();
	return (end - start);
}

void AVector::push_back(int n)
{
	_v.push_back(n);
}
