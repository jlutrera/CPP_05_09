#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	AList 	L;
	AVector	V;

	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe [list of positive integers]" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		int n = atoi(argv[i]);
		if (n < 0) 
		{
			std::cout << "Usage: ./PmergeMe [list of positive integers]" << std::endl;
			return 1;
		}
		L.push_back(n);
		V.push_back(n);
	}

	double lap;

	L.printList("Unsorted list: ");
    lap = L.sortList();
	L.printList("Sorted list  : ");
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with <list> container: " << lap << " ms" << std::endl;

	V.printVector("\nUnsorted array: ");
	lap = V.sortVector();
	V.printVector("Sorted array  : ");
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with <vector> container: " << lap << " ms" << std::endl;
 
    return 0;
}
