/**
 * 88. Merge Sorted Array
 * 
 * You are given two integer arrays 'p_numbersOne' and 'p_numbersTwo', sorted in non - decreasing order,
 * and two integers 'p_lengthOne' and 'p_lengthTwo', representing the number of elements in
 * 'p_numbersOne' and 'p_numbersTwo' respectively.
 * 
 * Merge 'p_numbersOne' and 'p_numbersTwo' into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead be stored inside the array 'p_numbersOne'.
 * To accommodate this, 'p_numbersOne' has a length of 'p_lengthOne' + 'p_lengthTwo',
 * where the first 'p_lengthOne' elements denote the elements that should be merged,
 * and the last 'p_lengthTwo' elements are set to 0 and should be ignored. 'p_numbersTwo' has a length of 'p_lengthTwo'.
 *
 */

#include <vector>
#include <iostream>

void merge(std::vector<int>& p_numbersOne, int p_lengthOne, std::vector<int>& p_numbersTwo, int p_lengthTwo)
{
    // special case
    if (p_numbersTwo.size() == 0) {
        return;
    }

    size_t indexOne = 0;
    size_t indexTwo = 0;

    // continues until end of first number list has been reached
    while (indexOne < p_lengthOne && indexTwo < p_lengthTwo) {
        if (p_numbersOne.at(indexOne) > p_numbersTwo.at(indexTwo)) {
            // shifts every number in the first list of numbers across by one
            for (size_t swapIndex = p_lengthOne; swapIndex > indexOne; swapIndex--) {
                p_numbersOne.at(swapIndex) = p_numbersOne.at(swapIndex - 1);
                p_numbersOne.at(swapIndex - 1) = 0;
            }
            p_lengthOne++;
            
            // inserts current number in second list of numbers into current position in first list of numbers
            p_numbersOne.at(indexOne) = p_numbersTwo.at(indexTwo);
            indexTwo++;
        }

        indexOne++;
    }

    // copies remaining values from second numbers list into the first one
    for (indexTwo; indexTwo < p_lengthTwo; indexTwo++) {
        p_numbersOne.at(indexOne) = p_numbersTwo.at(indexTwo);
        indexOne++;
    }
}

int main(void)
{
    std::vector<int> numbersOneOne = { 1, 2, 3, 0, 0, 0 };
    std::vector<int> numbersOneTwo = { 2, 5, 6 };

    merge(numbersOneOne, 3, numbersOneTwo, 3);

    // prints values of first merge
    for (int number : numbersOneOne) {
        std::cout << number << ", ";
    }

    std::cout << "\n";

    std::vector<int> numbersTwoOne = { 1 };
    std::vector<int> numbersTwoTwo = { };

    merge(numbersTwoOne, 1, numbersTwoTwo, 0);

    // prints values of second merge
    for (int number : numbersTwoOne) {
        std::cout << number << ", ";
    }

    std::cout << "\n";

    std::vector<int> numbersThreeOne = { 0 };
    std::vector<int> numbersThreeTwo = { 1 };

    merge(numbersThreeOne, 0, numbersThreeTwo, 1);

    // prints values of second merge
    for (int number : numbersThreeOne) {
        std::cout << number << ", ";
    }

    std::cout << "\n";
}
