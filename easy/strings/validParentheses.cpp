/**
 * 20. Valid Parentheses
 * 
 * Given a string 'p_text' containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 1) Open brackets must be closed by the same type of brackets.
 * 2) Open brackets must be closed in the correct order.
 * 3) Every close bracket has a corresponding open bracket of the same type.
 * 
 */

#include <iostream>
#include <stack>

bool isValid(const std::string& p_text)
{
    std::stack<char> openBrackets;

    for (char bracket : p_text) {
        // pushes open brackets to stack
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            openBrackets.push(bracket);
            continue;
        }

        // there is no preceding open bracket to match current close bracket
        if (openBrackets.size() == 0) {
            return false;
        }

        // gets open bracket at top of stack
        char topBracket = openBrackets.top();

        // compares with current close bracket
        if (topBracket == '(' && bracket == ')') {
            openBrackets.pop();
            continue;
        }

        if (topBracket == '[' && bracket == ']') {
            openBrackets.pop();
            continue;
        }

        if (topBracket == '{' && bracket == '}') {
            openBrackets.pop();
            continue;
        }

        return false;
    }

    // not all open brackets have been closed
    if (!openBrackets.empty()) {
        return false;
    }

    return true;
}

int main(void)
{
    std::cout << (isValid("()") ? "true" : "false") << "\n";
    std::cout << (isValid("()[]{}") ? "true" : "false") << "\n";
    std::cout << (isValid("(]") ? "true" : "false") << "\n";
}
