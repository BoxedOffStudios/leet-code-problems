/**
 * 58. Length of Last Word
 * 
 * Given a string 'p_word' consisting of words and spaces, return the length of the last word in the string.
 * 
 * A word is a maximal substring consisting of non-space characters only.
 * 
 */ 

#include <iostream>

int lengthOfLastWord(const std::string& p_words)
{
    size_t endOfLastWord = static_cast<size_t>(-1);

    for (int index = p_words.size() - 1; index >= 0; index--) {
        char character = p_words[index];

        // searches backwards for end of last word
        if (endOfLastWord == static_cast<size_t>(-1) && character != ' ') {
            endOfLastWord = index;
            continue;
        }

        // once end has been found,
        // continues searching backwards until start of last word is found
        if (endOfLastWord != static_cast<size_t>(-1) && character == ' ') {
            return endOfLastWord - index;
        }
    }

    // no spaces found
    return endOfLastWord + 1;
}

int main(void)
{
    std::cout << lengthOfLastWord("Hello World") << "\n";
    std::cout << lengthOfLastWord("   fly me   to   the moon  ") << "\n";
    std::cout << lengthOfLastWord("luffy is still joyboy") << "\n";
}
