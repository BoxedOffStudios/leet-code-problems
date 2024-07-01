/**
 * 1. Two Sum
 * 
 * Given an array of integers 'p_numbers' and an integer 'p_target',
 * return indices of the two numbers such that they add up to 'p_target'.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& p_numbers, int p_target)
{
    std::vector<int> answer;
    std::unordered_map<int, int> hashMap;

    for (int index = 0; index < p_numbers.size(); index++) {
        int valueAtIndex = p_numbers.at(index);
        int difference = p_target - valueAtIndex;

        if (hashMap.find(valueAtIndex) != hashMap.end()) {
            // success
            answer.push_back(hashMap.at(valueAtIndex));
            answer.push_back(index);
            return answer;
        }

        // failure
        hashMap[difference] = index;
    }

    return answer;
}

int main(void)
{
    std::vector<int> inputOne = { 2, 7, 11, 15 };
    std::vector<int> inputTwo = { 3, 2, 4 };
    std::vector<int> inputThree = { 3, 3 };

    std::vector<int> answersOne = twoSum(inputOne, 9);
    std::vector<int> answersTwo = twoSum(inputTwo, 6);
    std::vector<int> answersThree = twoSum(inputThree, 6);

    for (int answer : answersOne) {
        std::cout << answer << ", ";
    }
    std::cout << "\n";

    for (int answer : answersTwo) {
        std::cout << answer << ", ";
    }
    std::cout << "\n";

    for (int answer : answersThree) {
        std::cout << answer << ", ";
    }
    std::cout << "\n";
}
