#include <iostream>
#include <list>

// Merge two sorted lists into a single sorted list
std::list<int> merge(std::list<int>& left, std::list<int>& right) {
    std::list<int> result;

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

// Recursive function to perform merge sort on a list
std::list<int> mergeSort(std::list<int>& input) {
    if (input.size() <= 1) {
        return input;
    }

    std::list<int> left, right;
    int middle = input.size() / 2;
    int count = 0;

    for (std::list<int>::iterator it = input.begin(); it != input.end(); ++it) {
        if (count < middle) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
        count++;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    std::list<int> input;
    input.push_back(12);
    input.push_back(11);
    input.push_back(13);
    input.push_back(5);
    input.push_back(6);
    input.push_back(7);

    std::cout << "Unsorted list: ";
    for (std::list<int>::iterator it = input.begin(); it != input.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<int> sortedList = mergeSort(input);

    std::cout << "Sorted list: ";
    for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
