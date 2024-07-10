/**
 * 101. Symmetric Tree
 *
 * Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 *
 */

#include <queue>
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

bool isSymmetric(TreeNode* p_leftTree, TreeNode* p_rightTree)
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

    return (isSymmetric(p_leftTree->leftNode, p_rightTree->rightNode) &&
            isSymmetric(p_leftTree->rightNode, p_rightTree->leftNode));
}

bool isSymmetric(TreeNode* p_rootNode)
{
    return isSymmetric(p_rootNode->leftNode, p_rootNode->rightNode);
}

int main(void)
{
    TreeNode nodeOneSeven(3);
    TreeNode nodeOneSix(4);
    TreeNode nodeOneFive(4);
    TreeNode nodeOneFour(3);
    TreeNode nodeOneThree(2, &nodeOneSix, &nodeOneSeven);
    TreeNode nodeOneTwo(2, &nodeOneFour, &nodeOneFive);
    TreeNode nodeOneOne(1, &nodeOneTwo, &nodeOneThree);

    std::cout << (isSymmetric(&nodeOneOne) ? "true" : "false") << "\n";
}
