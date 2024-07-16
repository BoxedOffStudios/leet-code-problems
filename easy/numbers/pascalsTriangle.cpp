/**
 * 118. Pascal's Triangle
 * 
 * Given an integer 'p_rowsCount', return the first 'p_rowsCount' rows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 */

#include <vector>
#include <iostream>

std::vector<std::vector<int>> generate(int p_rowsCount)
{
    // intialises with enough room for each row
    std::vector<std::vector<int>> triangle(p_rowsCount);
    // sets top value of pascal's triangle to be a 1
    std::vector<int> previousRow = { 1 };
    triangle.at(0) = previousRow;

    auto getValueFromPreviousRow = [&](int p_indexIntoRow) -> int
    {
        if (p_indexIntoRow < 0 || p_indexIntoRow >= previousRow.size()) {
            return 0;
        }

        return previousRow.at(p_indexIntoRow);
    };

    int rowLength = 2;

    for (int rowIndex = 1; rowIndex < p_rowsCount; rowIndex++) {
        std::vector<int> currentRow(rowLength);

        for (int indexIntoRow = 0; indexIntoRow < rowLength; indexIntoRow++) {
            // uses sum of the value above and the value just before that one to calculate current value
            int sumFromAbove = (getValueFromPreviousRow(indexIntoRow) +
                                getValueFromPreviousRow(indexIntoRow - 1));

            currentRow.at(indexIntoRow) = sumFromAbove;
        }

        // appends to triangle and prepares for the next row
        triangle.at(rowIndex) = currentRow;
        previousRow = currentRow;
        rowLength++;
    }

    return triangle;
}

int main(void)
{
    std::vector<std::vector<int>> triangleOne = generate(5);

    // printing the triangle as an array
    std::cout << "[";

    for (const std::vector<int>& row : triangleOne) {
        std::cout << "[";

        for (int value : row) {
            std::cout << value << ", ";
        }

        std::cout << "], ";
    }
}
