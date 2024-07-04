/**
 * 66. Plus One
 * 
 * You are given a large integer represented as an integer array 'p_digits',
 * where each 'p_digits[i]' is the ith digit of the integer.
 * The digits are ordered from most significant to least significant in left-to-right order.
 * The large integer does not contain any leading 0's.
 * 
 * Increment the large integer by one and return the resulting array of digits.
 * 
 */

#include <vector>
#include <iostream>

std::vector<int> plusOne(const std::vector<int>& p_digits)
{
    // creates editable copy
    std::vector<int> digitsNew(p_digits);

    // if last digit is a 9 then work backwards until non-nine found or end is reached
    auto iterator = digitsNew.rbegin();

    while (iterator != digitsNew.rend() && *iterator == 9) {
        *iterator = 0;

        iterator++;
    }

    // digits were all nines
    if (iterator == digitsNew.rend()) {
        digitsNew.insert(digitsNew.begin(), 1);
    }
    else {
        // increments first non-nine digit
        (*iterator)++;
    }

    return digitsNew;
}

int main(void)
{
    std::vector<int> digitsOne = { 1, 2, 3 };
    std::vector<int> answerOne = plusOne(digitsOne);

    for (int digit : answerOne) {
        std::cout << digit << ", ";
    }
    std::cout << "\n";

    std::vector<int> digitsTwo = { 4, 3, 2, 1 };
    std::vector<int> answerTwo = plusOne(digitsTwo);

    for (int digit : answerTwo) {
        std::cout << digit << ", ";
    }
    std::cout << "\n";

    std::vector<int> digitsThree = { 9 };
    std::vector<int> answerThree = plusOne(digitsThree);

    for (int digit : answerThree) {
        std::cout << digit << ", ";
    }
    std::cout << "\n";
}
