#include <iostream>
#include <vector>
#include <list>

std::list<int> merge_list(std::list<int>& left, std::list<int>& right)
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

// Merge two subarrays of vector arr[]
// First subarray is arr[l..m], second subarray is arr[m+1..r]
void merge_vector(std::vector<int>& arr, int l, int m, int r)
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

// Recursive function to perform merge sort on a list
std::list<int> mergeSort_list(std::list<int>& input)
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

    left = mergeSort_list(left);
    right = mergeSort_list(right);

    return merge_list(left, right);
}

// Recursive function to perform merge sort on the vector
void mergeSort_vector(std::vector<int>& arr, int l, int r)
{
    if (l < r)
	{
        int m = l + (r - l) / 2;
        mergeSort_vector(arr, l, m);
        mergeSort_vector(arr, m + 1, r);
        merge_vector(arr, l, m, r);
    }
}

int main()
{
	std::list<int> input;
    input.push_back(15);
    input.push_back(14);
    input.push_back(13);
    input.push_back(12);
    input.push_back(11);
    input.push_back(10);

    std::cout << "Unsorted list: ";
    for (std::list<int>::iterator it = input.begin(); it != input.end(); ++it)
		std::cout << *it << " ";
    std::cout << std::endl;

    std::list<int> sortedList = mergeSort_list(input);

    std::cout << "Sorted list: ";
    for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::vector<int> arr;
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);

    std::cout << "Unsorted array: ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    int arrSize = arr.size();

    mergeSort_vector(arr, 0, arrSize - 1);

    std::cout << "Sorted array: ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
