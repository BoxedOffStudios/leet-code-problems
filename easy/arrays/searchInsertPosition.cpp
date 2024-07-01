/**
 * 35. Search Insert Position
 * 
 * Given a sorted array of distinct integers and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 */

#include <vector>
#include <iostream>

int searchInsert(const std::vector<int>& p_numbers, int p_target)
{
    size_t halfwayIndex = p_numbers.size() / 2U;
    int valueAtHalfway = p_numbers.at(halfwayIndex);

    // successfully found target
    if (valueAtHalfway == p_target) {
        return halfwayIndex;
    }

    // chooses left half of list
    if (p_target < valueAtHalfway) {
        auto start = p_numbers.begin();
        auto end = std::next(p_numbers.begin(), halfwayIndex);

        std::vector<int> refinedNumbers(start, end);

        // there is nothing to the left
        if (refinedNumbers.size() == 0) {
            return 0;
        }

        return searchInsert(refinedNumbers, p_target);
    }

    // chooses right half of list
    auto start = std::next(p_numbers.begin(), halfwayIndex + 1);
    auto end = p_numbers.end();

    std::vector<int> refinedNumbers(start, end);

    // there is nothing to the right
    if (refinedNumbers.size() == 0) {
        return halfwayIndex + 1;
    }

    return halfwayIndex + 1 + searchInsert(refinedNumbers, p_target);
}

int main(void)
{
    std::vector<int> numbers = { 1, 3, 5, 6, 9, 13 };
    std::cout << searchInsert(numbers, 8) << "\n";
    std::cout << searchInsert(numbers, 25) << "\n";
    std::cout << searchInsert(numbers, 5) << "\n";
}
