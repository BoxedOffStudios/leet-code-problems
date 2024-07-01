/**
 * 27. Remove Element 
 *  
 * Given an integer array 'p_numbers' and an integer 'p_value', remove all occurrences of 'p_value' in 'p_numbers' in-place.
 * The order of the elements may be changed. Then return the number of elements in 'p_numbers' which are not equal to 'p_value'.
 * 
 * Consider the number of elements in 'p_numbers' which are not equal to 'p_value' be 'count', to get accepted,
 * you need to do the following things:
 * 
 * - Change the array 'p_numbers' such that the first 'count' elements of 'p_numbers' contain the elements which are
 *   not equal to 'p_value'.
 *   The remaining elements of 'p_numbers' are not important as well as the size of 'p_numbers'.
 * 
 * - Return 'count'.
 * 
 */

#include <iostream>
#include <vector>

int removeElement(std::vector<int>& p_numbers, const int p_value)
{
    size_t nonValueIndex = 0;

    for (size_t index = 0; index < p_numbers.size(); index++) {
        int currentNumber = p_numbers.at(index);
        
        if (currentNumber != p_value) {
            p_numbers.at(nonValueIndex) = currentNumber;
            nonValueIndex++;
        }
    }

    return nonValueIndex;
}

int main(void)
{
    std::vector<int> numbersOne = { 3, 2, 2, 3 };
    std::vector<int> numbersTwo = { 0, 1, 2, 2, 3, 0, 4, 2 };

    // prints first list after removing an element
    int count = removeElement(numbersOne, 3);

    for (int index = 0; index < count; index++) {
        std::cout << numbersOne[index] << ", ";
    }

    std::cout << "\n";

    // prints second list after removing an element
    count = removeElement(numbersTwo, 2);

    for (int index = 0; index < count; index++) {
        std::cout << numbersTwo[index] << ", ";
    }

    std::cout << "\n";
}
