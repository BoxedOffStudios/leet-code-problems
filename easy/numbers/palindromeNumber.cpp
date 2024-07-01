/**
 * 9. Palindrome Number
 * 
 * Given an integer 'p_number', return true if 'p_number' is a palindrome, and false otherwise.
 * 
 */

#include <iostream>
#include <string>

bool isPalindrome(int p_number)
{
    std::string digits = std::to_string(p_number);

    int searchEnd = digits.size() / 2;

    // searches from both ends inwards until either meeting the middle or finding unmatching digits.
    for (int index = 0; index < searchEnd; index++) {
        if (digits.at(index) != digits.at(digits.size() - index - 1)) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    std::cout << (isPalindrome(121) ? "true" : "false") << "\n";
    std::cout << (isPalindrome(-121) ? "true" : "false") << "\n";
    std::cout << (isPalindrome(10) ? "true" : "false") << "\n";
}
