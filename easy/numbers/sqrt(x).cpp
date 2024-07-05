/**
 * 69. Sqrt(x)
 * 
 * Given a non-negative integer 'p_number', return the square root of 'p_number' rounded down to the nearest integer.
 * The returned integer should be non-negative as well.
 * 
 * You must not use any built-in exponent function or operator.
 *
 */

#include <cassert>
#include <iostream>

int mySqrt(unsigned long p_number)
{
    // special cases
    if (p_number == 0 || p_number == 1) {
        return p_number;
    }

    unsigned long upperBound = p_number;
    unsigned long lowerBound = 0;

    unsigned long halfwayBound = 0;
    unsigned long long halfwaySquared = 0;

    while (upperBound >= lowerBound) {
        halfwayBound = (lowerBound + upperBound) / 2;
        halfwaySquared = static_cast<unsigned long long>(halfwayBound);
        halfwaySquared *= halfwaySquared;

        // found number
        if (p_number == halfwaySquared) {
            return halfwayBound;
        }

        // checks numbers to the right
        if (p_number > halfwaySquared) {
            lowerBound = halfwayBound + 1;
            continue;
        }

        // checks numbers to the left
        upperBound = halfwayBound - 1;
    }

    // couldn't find it exactly
    return upperBound;
}

int main(void)
{
    std::cout << mySqrt(4) << "\n";
    std::cout << mySqrt(8) << "\n";
}
