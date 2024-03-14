#include <iostream>
#include <list>

// Function to sort a list in ascending order
void sortList(std::list<int>& lst) {
    lst.sort();
}

// Function to merge two sorted lists into a single sorted list
std::list<int> mergeLists(const std::list<int>& lst1, const std::list<int>& lst2) {
    std::list<int> merged;
    auto it1 = lst1.begin();
    auto it2 = lst2.begin();

    while (it1 != lst1.end() && it2 != lst2.end()) {
        if (*it1 < *it2) {
            merged.push_back(*it1);
            ++it1;
        } else {
            merged.push_back(*it2);
            ++it2;
        }
    }

    // Add remaining elements from lst1 (if any)
    while (it1 != lst1.end()) {
        merged.push_back(*it1);
        ++it1;
    }

    // Add remaining elements from lst2 (if any)
    while (it2 != lst2.end()) {
        merged.push_back(*it2);
        ++it2;
    }

    return merged;
}

int main() {
    std::list<int> list1 = {5, 2, 8, 1, 9};
    std::list<int> list2 = {3, 6, 7, 4};

    std::cout << "List 1: ";
    for (int num : list1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "List 2: ";
    for (int num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sortList(list1);
    sortList(list2);

    std::cout << "Sorted List 1: ";
    for (int num : list1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted List 2: ";
    for (int num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::list<int> merged = mergeLists(list1, list2);
    std::cout << "Merged List: ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}