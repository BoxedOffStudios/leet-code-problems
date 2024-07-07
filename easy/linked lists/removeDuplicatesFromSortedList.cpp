/**
 * 83. Remove Duplicates from Sorted List
 * 
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
 * Return the linked list sorted as well.
 * 
 */

#include <iostream>

struct ListNode
{
    ListNode() : value(0), nextNode(nullptr) {}
    ListNode(int p_value) : value(p_value), nextNode(nullptr) {}
    ListNode(int p_value, ListNode* p_nextNode) : value(p_value), nextNode(p_nextNode) {}

    int value;
    ListNode* nextNode;
};

ListNode* deleteDuplicates(ListNode* p_headNode)
{
    // empty list should return empty regardless
    if (p_headNode == nullptr) {
        return nullptr;
    }

    ListNode* currentNode = p_headNode;
    ListNode* nextNode = currentNode->nextNode;

    while (nextNode != nullptr) {
        // duplicates found - continue searching until non-duplicate is found
        if (currentNode->value == nextNode->value) {
            nextNode = nextNode->nextNode;
            continue;
        }

        // non-duplicate found - skips duplicates and attaches current node to next node
        currentNode->nextNode = nextNode;
        
        // prepares for next run of the loop
        currentNode = nextNode;
        nextNode = currentNode->nextNode;
    }

    // chops off excess
    currentNode->nextNode = nullptr;

    return p_headNode;
}

int main(void)
{
    ListNode nodeOneThree(2);
    ListNode nodeOneTwo(1, &nodeOneThree);
    ListNode nodeOneOne(1, &nodeOneTwo);

    ListNode* solutionOne = deleteDuplicates(&nodeOneOne);

    // prints results from first list's duplicate culling
    ListNode* currentOne = solutionOne;

    while (currentOne != nullptr) {
        std::cout << currentOne->value << ", ";
        currentOne = currentOne->nextNode;
    }

    std::cout << "\n";

    ListNode nodeTwoFive(3);
    ListNode nodeTwoFour(3, &nodeTwoFive);
    ListNode nodeTwoThree(2, &nodeTwoFour);
    ListNode nodeTwoTwo(1, &nodeTwoThree);
    ListNode nodeTwoOne(1, &nodeTwoTwo);

    ListNode* solutionTwo = deleteDuplicates(&nodeTwoOne);

    // prints results from second list's duplicate culling
    ListNode* currentTwo = solutionTwo;

    while (currentTwo != nullptr) {
        std::cout << currentTwo->value << ", ";
        currentTwo = currentTwo->nextNode;
    }

    std::cout << "\n";
}
