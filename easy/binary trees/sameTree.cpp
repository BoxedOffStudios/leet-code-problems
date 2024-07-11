/** 
 * 100. Same Tree
 * 
 * Given the roots of two binary trees 'p_firstRoot' and 'p_secondRoot', write a function to check if they are the same or not.
 * 
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * 
 */

#include <iostream>

struct TreeNode
{
    TreeNode()
        : value(0), leftNode(nullptr), rightNode(nullptr) {}
    TreeNode(int p_value)
        : value(p_value), leftNode(nullptr), rightNode(nullptr) {}
    TreeNode(int p_value, TreeNode* p_leftNode, TreeNode* p_rightNode)
        : value(p_value), leftNode(p_leftNode), rightNode(p_rightNode) {}

    int value;
    TreeNode* leftNode;
    TreeNode* rightNode;
};

bool isSameTree(TreeNode* p_leftTree, TreeNode* p_rightTree)
{
    if (p_leftTree == nullptr && p_rightTree == nullptr) {
        return true;
    }

    if (p_leftTree == nullptr || p_rightTree == nullptr) {
        return false;
    }

    if (p_leftTree->value != p_rightTree->value) {
        return false;
    }

    return (isSameTree(p_leftTree->leftNode, p_rightTree->leftNode) &&
            isSameTree(p_leftTree->rightNode, p_rightTree->rightNode));
}

int main(void)
{
    TreeNode nodeOneThree(3);
    TreeNode nodeOneTwo(2);
    TreeNode nodeOneOne(1, &nodeOneTwo, &nodeOneThree);

    TreeNode nodeTwoThree(3);
    TreeNode nodeTwoTwo(2);
    TreeNode nodeTwoOne(1, &nodeTwoTwo, &nodeTwoThree);

    std::cout << (isSameTree(&nodeOneOne, &nodeTwoOne) ? "true" : "false") << "\n";
}
