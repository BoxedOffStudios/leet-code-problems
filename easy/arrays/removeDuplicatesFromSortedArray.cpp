/**
 * 26. Remove Duplicates from Sorted Array
 * 
 * Given an integer array 'p_numbers' sorted in non-decreasing order, remove the duplicates in-place such that
 * each unique element appears only once. The relative order of the elements should be kept the same.
 * Then return the number of unique elements in 'p_numbers'.
 * 
 * Consider the number of unique elements of 'p_numbers' to be 'count', to get accepted, you need to do the following things:
 * 
 * - Change the array 'p_numbers' such that the first 'count' elements of 'p_numbers' contain the unique elements
 *   in the order they were present in 'p_numbers' initially.
 *   The remaining elements of 'p_numbers' are not important as well as the size of 'p_numbers'.
 * 
 * - Return 'count'.
 * 
 */

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& p_numbers)
{
    auto swapNumbers = [&p_numbers](const size_t p_indexOne, const size_t p_indexTwo)
    {
        int temp = p_numbers.at(p_indexOne);

        p_numbers.at(p_indexOne) = p_numbers.at(p_indexTwo);
        p_numbers.at(p_indexTwo) = temp;
    };

    size_t indexAnchor = 0;

    // explores from index 1 to last index in numbers vector for next greatest number
    for (size_t indexExplore = 1; indexExplore < p_numbers.size(); indexExplore++) {
        int anchor = p_numbers.at(indexAnchor);
        int explore = p_numbers.at(indexExplore);

        if (explore > anchor) {
            swapNumbers(++indexAnchor, indexExplore);
        }
    }

    return indexAnchor + 1;
}

int main(void)
{
    std::vector<int> numbersOne = { 1, 1, 2 };
    std::vector<int> numbersTwo = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    // prints first list
    int count = removeDuplicates(numbersOne);

    for (int index = 0; index < count; index++) {
        std::cout << numbersOne[index] << ", ";
    }
    
    std::cout << "\n";

    // prints second list
    count = removeDuplicates(numbersTwo);

    for (int index = 0; index < count; index++) {
        std::cout << numbersTwo[index] << ", ";
    }
}
