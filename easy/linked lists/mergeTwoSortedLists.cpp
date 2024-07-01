/**
 * 21. Merge Two Sorted Lists
 * 
 * You are given the heads of two sorted linked lists 'p_listOne' and 'p_listTwo'.
 * 
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * 
 * Return the head of the merged linked list.
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

ListNode* mergeTwoLists(ListNode* p_listOne, ListNode* p_listTwo)
{
    // returns second list if first is empty
    if (p_listOne == nullptr) {
        return p_listTwo;
    }

    // points to head of list one - to return fully merged list
    ListNode* mergedList = p_listOne;

    auto insertNodeBefore = [](ListNode* p_node, ListNode* p_location)
    {
        // swaps values between location and node
        int locationValue = p_location->value;
        p_location->value = p_node->value;
        p_node->value = locationValue;

        // attaches before node to current node
        ListNode* nextLocation = p_location->nextNode;
        p_location->nextNode = p_node;
        p_node->nextNode = nextLocation;
    };

    while (p_listTwo != nullptr) {
        // current node in list one is smaller than that of list two
        if (p_listOne->value <= p_listTwo->value) {
            // adds remainder of list two to list one
            if (p_listOne->nextNode == nullptr) {
                p_listOne->nextNode = p_listTwo;
                break;
            }
            
            // proceeds to next node in list one
            p_listOne = p_listOne->nextNode;
            continue;
        }

        ListNode* nextTwo = p_listTwo->nextNode;

        // inserts list two's current node before current node in list one
        insertNodeBefore(p_listTwo, p_listOne);

        // proceeds to next node in both lists
        p_listOne = p_listOne->nextNode;
        p_listTwo = nextTwo;
    }

    return mergedList;
}

int main(void)
{
    ListNode listOneThree(7);
    ListNode listOneTwo(5, &listOneThree);
    ListNode listOneOne(1, &listOneTwo);

    ListNode listTwoThree(8);
    ListNode listTwoTwo(4, &listTwoThree);
    ListNode listTwoOne(2, &listTwoTwo);

    ListNode* mergedList = mergeTwoLists(&listOneOne, &listTwoOne);
    ListNode* mergedCurrent = mergedList;

    // outputs merged list
    while (mergedCurrent != nullptr) {
        std::cout << mergedCurrent->value << ", ";
        mergedCurrent = mergedCurrent->nextNode;
    }
}
