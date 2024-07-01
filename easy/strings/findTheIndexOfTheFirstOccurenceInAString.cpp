/**
 * 28. Find the Index of the First Occurence in a String
 * 
 * Given two strings 'p_needle' and 'p_haystack', return the index of the first occurrence of 'p_needle' in 'p_haystack',
 * or -1 if 'p_needle' is not part of 'p_haystack'.
 * 
 */

#include <iostream>

int getIndexOfFirstOccurence(const std::string& p_haystack, const std::string& p_needle)
{
    for (size_t haystackIndex = 0; haystackIndex < p_haystack.size(); haystackIndex++)
    {
        size_t currentHaystackIndex = haystackIndex;
        size_t needleIndex = 0;
        
        char characterInHaystack = p_haystack.at(haystackIndex);
        char characterInNeedle = p_needle.at(needleIndex);

        // begins comparing all subsequent characters to check for a match
        while (characterInHaystack == characterInNeedle)
        {
            needleIndex++;
            haystackIndex++;

            // all characters of needle are present in haystack
            if (needleIndex >= p_needle.size()) {
                return haystackIndex - p_needle.size();
            }
            characterInNeedle = p_needle.at(needleIndex);

            // ensures end of haystack has not been reached
            if (haystackIndex >= p_haystack.size()) {
                break;
            }
            characterInHaystack = p_haystack.at(haystackIndex);
        }

        haystackIndex = currentHaystackIndex;
    }

    return -1;
}

int main(void)
{
    std::cout << getIndexOfFirstOccurence("sadbutsad", "sad") << "\n";
    std::cout << getIndexOfFirstOccurence("leetcode", "leeto") << "\n";
}
