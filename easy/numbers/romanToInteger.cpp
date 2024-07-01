/**
 * 13. Roman to Integer
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * 
 *   Symbol       Value
 *   I             1
 *   V             5
 *   X             10
 *   L             50
 *   C             100
 *   D             500
 *   M             1000
 * 
 * For example, 2 is written as II in Roman numeral, just two ones added together.
 * 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is written as IV.
 * Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * 
 * - I can be placed before V (5) and X (10) to make 4 and 9. 
 * - X can be placed before L (50) and C (100) to make 40 and 90. 
 * - C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given a roman numeral, convert it to an integer.
 * 
 */ 

#include <iostream>
#include <string>

int romanToInt(const std::string& p_romanNumeral)
{
    auto specialCase = [=](int& p_value, int& p_index, int p_power, const char p_followingOne, const char p_followingTwo) -> void
    {
        // ensures not last element
        if (p_index + 1 < p_romanNumeral.size()) {
            char nextCharacter = p_romanNumeral.at(p_index + 1);

            if (nextCharacter == p_followingOne) {
                p_value += (4 * p_power);
                p_index++;
                return;
            }

            if (nextCharacter == p_followingTwo) {
                p_value += (9 * p_power);
                p_index++;
                return;
            }
        }

        p_value += (1 * p_power);
    };

    int value = 0;

    for (int index = 0; index < p_romanNumeral.size(); index++) {
        char character = p_romanNumeral.at(index);

        switch (character) {
        case 'I':
            specialCase(value, index, 1, 'V', 'X');
            continue;
        case 'V':
            value += 5;
            continue;
        case 'X':
            specialCase(value, index, 10, 'L', 'C');
            continue;
        case 'L':
            value += 50;
            continue;
        case 'C':
            specialCase(value, index, 100, 'D', 'M');
            continue;
        case 'D':
            value += 500;
            continue;
        case 'M':
            value += 1000;
            continue;
        }
    }

    return value;
}

int main(void)
{
    std::cout << romanToInt("III") << "\n";
    std::cout << romanToInt("LVIII") << "\n";
    std::cout << romanToInt("MCMXCIV") << "\n";
}
