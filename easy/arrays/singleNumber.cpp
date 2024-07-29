/**
 * 136. Single Number
 * 
 * Given a non-empty array of integers 'p_numbers', every element appears twice except for one. Find that single one.
 * 
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 * 
 */

#include <vector>
#include <iostream>

int singleNumber(const std::vector<int>& p_numbers)
{
    int singleNumber = 0;

    // flips the bits of each number until its pair comes along and the bits are flipped back
    // the only remaining bits unflipped at the end belong to the number that didn't have a pair
    for (int number : p_numbers) {
        singleNumber ^= number;
    }

    return singleNumber;
}

int main(void)
{
    std::cout << singleNumber({ 2, 2, 1 }) << "\n";
    std::cout << singleNumber({ 4, 1, 2, 1, 2 }) << "\n";
    std::cout << singleNumber({ 1 }) << "\n";
}
