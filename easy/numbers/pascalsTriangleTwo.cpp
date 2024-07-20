/**
 * 119. Pascal's Triangle II
 *
 * Given an integer 'p_rowIndex', return the 'p_rowIndex'th(0 - indexed) row of the Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 */

#include <vector>
#include <iostream>

/**
 * @return value of p_firstValue choose p_secondValue.
 */
long int choose(long int p_firstValue, long int p_secondValue)
{
    if (p_secondValue == 0) {
        return 1;
    }
    
    return (p_firstValue * choose(p_firstValue - 1, p_secondValue - 1)) / p_secondValue;
}

std::vector<int> getRow(int p_rowIndex)
{
    std::vector<int> row;

    for (int columnIndex = 0; columnIndex < p_rowIndex + 1; columnIndex++) {
        int value = choose(p_rowIndex, columnIndex);
        row.push_back(value);
    }

    return row;
}

int main(void)
{
    std::vector<int> rowOne = getRow(13);
    for (int value : rowOne) {
        std::cout << value << ", ";
    }
    std::cout << "\n";
}
