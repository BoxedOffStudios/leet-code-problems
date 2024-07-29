/**
 * 141. Linked List Cycle
 * 
 * Given 'p_head', the head of a linked list, determine if the linked list has a cycle in it.
 * 
 * There is a cycle in a linked list if there is some node in the list that can be reached again by
 * continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
 * Note that pos is not passed as a parameter.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 */

#include <vector>
#include <iostream>

struct ListNode
{
    ListNode() : value(0), nextNode(nullptr) {}
    ListNode(int p_value) : value(p_value), nextNode(nullptr) {}
    ListNode(int p_value, ListNode* p_nextNode) : value(p_value), nextNode(p_nextNode) {}
    
    int value;
    ListNode* nextNode;
};

bool hasCycle(ListNode* p_head)
{
    ListNode* walkingNode = p_head;
    ListNode* lappingNode = p_head;

    // ensures we are not at a tail
    while (lappingNode && lappingNode->nextNode) {
        walkingNode = walkingNode->nextNode;
        lappingNode = lappingNode->nextNode->nextNode;

        // due to loop, lapping node has lapped and landed on walking node
        if (walkingNode == lappingNode) {
            return true;
        }
    }

    return false;
}

int main(void)
{
    ListNode nodeOneFour(-4);
    ListNode nodeOneThree(0, &nodeOneFour);
    ListNode nodeOneTwo(2, &nodeOneThree);
    ListNode nodeOneOne(3, &nodeOneTwo);
    nodeOneFour.nextNode = &nodeOneTwo;

    std::cout << (hasCycle(&nodeOneOne) ? "true" : "false") << "\n";

    ListNode nodeTwoTwo(2);
    ListNode nodeTwoOne(1, &nodeTwoTwo);
    nodeTwoTwo.nextNode = &nodeTwoOne;

    std::cout << (hasCycle(&nodeTwoOne) ? "true" : "false") << "\n";

    ListNode nodeThree(1);

    std::cout << (hasCycle(&nodeThree) ? "true" : "false") << "\n";
}
