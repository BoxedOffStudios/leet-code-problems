/**
 * 14. Longest Common Prefix
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 */ 

#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& p_words)
{
    if (p_words.size() == 1) {
        return p_words.at(0);
    }

    std::string prefix;

    unsigned int characterIndex = 0;
    unsigned int wordIndex = 0;

    char characterToMatch = '\0';
    char currentCharacter = '\0';

    // loops until a word has reached its character limit
    while (characterIndex < p_words.at(wordIndex).size()) {
        // first word sets character to match
        if (wordIndex == 0) {
            characterToMatch = p_words.at(wordIndex).at(characterIndex);
        }

        currentCharacter = p_words.at(wordIndex).at(characterIndex);

        // checks whether character matches in current word
        if (currentCharacter != characterToMatch) {
            break;
        }

        // checks whether end of words list reached
        if (wordIndex >= p_words.size() - 1) {
            prefix += characterToMatch;

            // resets for next character
            wordIndex = 0;
            characterIndex++;
            continue;
        }

        wordIndex++;
    }

    return prefix;
}

int main(void)
{
    const std::vector<std::string> testOne = { "flower", "flow", "flight" };
    const std::vector<std::string> testTwo = { "dog", "racecar", "car" };

    std::cout << longestCommonPrefix(testOne) << "\n";
    std::cout << longestCommonPrefix(testTwo) << "\n";
}
