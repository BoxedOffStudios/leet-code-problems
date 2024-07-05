/**
 * 67. Add Binary
 * 
 * Given two binary strings 'p_firstNumber' and 'p_secondNumber', return their sum as a binary string.
 *
 */

#include <string>
#include <iostream>

std::string addBinary(const std::string& p_firstNumber, const std::string& p_secondNumber)
{
    std::string summation;
    char carryBit = '0';

    auto getCurrentSummation = [&carryBit](char p_currentFirst, char p_currentSecond) -> char
    {
        // refrains from adding the zero carry bit when both numbers have reached their ends
        if (p_currentFirst == '\0' && p_currentSecond == '\0' && carryBit == '0') {
            return '\0';
        }

        // all three are ones
        if (p_currentFirst == '1' && p_currentSecond == '1' && carryBit == '1') {
            carryBit = '1';
            return '1';
        }

        // two of the three are ones
        if ((p_currentFirst == '1' && p_currentSecond == '1') ||
            (p_currentFirst == '1' && carryBit == '1') ||
            (p_currentSecond == '1' && carryBit == '1'))
        {
            carryBit = '1';
            return '0';
        }

        // only one of the three is a one
        if (p_currentFirst == '1' || p_currentSecond == '1' || carryBit == '1') {
            carryBit = '0';
            return '1';
        }

        // there are no ones
        carryBit = '0';
        return '0';
    };

    auto getCurrentCharacter = [](const std::string& p_number, size_t p_index) -> char
    {
        // valid index
        if (p_index < p_number.size()) {
            return p_number.at(p_number.size() - 1 - p_index);
        }

        // invalid index
        return '\0';
    };

    size_t index = 0;
    char currentFirst = '\0';
    char currentSecond = '\0';

    // only stops once the end of one of these numbers has been reached
    do {
        currentFirst = getCurrentCharacter(p_firstNumber, index);
        currentSecond = getCurrentCharacter(p_secondNumber, index);

        // prepends sum of the carry bit and the current characters in the first and second numbers
        char currentSummation = getCurrentSummation(currentFirst, currentSecond);
        if (currentSummation != '\0') {
            summation = currentSummation + summation;
        }

        index++;
    } while (currentFirst != '\0' || currentSecond != '\0');

    return summation;
}

int main(void)
{
    std::cout << addBinary("11", "1") << "\n";
    std::cout << addBinary("1010", "1011") << "\n";
    std::cout << addBinary("100", "110010") << "\n";
    std::cout << addBinary("1", "1") << "\n";
}
