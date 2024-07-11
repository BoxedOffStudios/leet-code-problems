/**
 * 104. Maximum Depth of Binary Tree
 *
 * Given the root of a binary tree, return its maximum depth.
 * 
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
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

int maxDepth(TreeNode* p_tree)
{
    if (p_tree == nullptr) {
        return 0;
    }

    return 1 + std::max(maxDepth(p_tree->leftNode), maxDepth(p_tree->rightNode));
}

int main(void)
{
    TreeNode nodeOneFive(7);
    TreeNode nodeOneFour(15);
    TreeNode nodeOneThree(20, &nodeOneFour, &nodeOneFive);
    TreeNode nodeOneTwo(9);
    TreeNode nodeOneOne(3, &nodeOneTwo, &nodeOneThree);

    std::cout << maxDepth(&nodeOneOne) << "\n";

    TreeNode nodeTwoTwo(2);
    TreeNode nodeTwoOne(1, nullptr, &nodeTwoTwo);

    std::cout << maxDepth(&nodeTwoOne) << "\n";
}
