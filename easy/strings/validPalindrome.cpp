/**
 * 125. Valid Palindrome
 * 
 * A phrase is a palindrome if,
 * after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
 * it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * 
 * Given a string 'p_phrase', return true if it is a palindrome, or false otherwise.
 * 
 */

#include <string>
#include <iostream>

std::string formatPhrase(const std::string& p_phrase)
{
    constexpr int asciiOfA = static_cast<int>('a');
    constexpr int asciiOfZ = static_cast<int>('z');
    constexpr int asciiOfZero = static_cast<int>('0');
    constexpr int asciiOfNine = static_cast<int>('9');

    std::string formattedPhrase;

    for (char character : p_phrase) {
        // formats to lowercase
        character = std::tolower(character);

        // ensures that character is within range of a-z or 0-9
        int asciiOfCharacter = static_cast<int>(character);

        if ((asciiOfCharacter >= asciiOfA && asciiOfCharacter <= asciiOfZ) ||
            (asciiOfCharacter >= asciiOfZero && asciiOfCharacter <= asciiOfNine))
        {
            formattedPhrase += character;
        }
    }

    return formattedPhrase;
}

bool isPalindrome(std::string p_phrase)
{
    p_phrase = formatPhrase(p_phrase);
    
    size_t halfwayIndex = p_phrase.size() / 2;

    for (size_t index = 0; index < halfwayIndex; index++) {
        if (p_phrase.at(index) != p_phrase.at(p_phrase.size() - 1 - index)) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    std::cout << (isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << "\n";
    std::cout << (isPalindrome("race a car") ? "true" : "false") << "\n";
    std::cout << (isPalindrome(" ") ? "true" : "false") << "\n";
}
