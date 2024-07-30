/**
 * 94. Binary Tree Inorder Traversal
 * 
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 
 */

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

#include <vector>
#include <iostream>

void inorderTraversal(std::vector<int>& p_traversal, TreeNode* p_rootNode)
{
    if (!p_rootNode) {
        return;
    }

    // adds current node after exploring left child but before exploring the right - INbetween
    inorderTraversal(p_traversal, p_rootNode->leftNode);
    p_traversal.push_back(p_rootNode->value);
    inorderTraversal(p_traversal, p_rootNode->rightNode);
}

std::vector<int> inorderTraversal(TreeNode* p_rootNode)
{
    std::vector<int> traversal;
    inorderTraversal(traversal, p_rootNode);
    return traversal;
}

int main(void)
{
    TreeNode nodeOneThree(3);
    TreeNode nodeOneTwo(2, &nodeOneThree, nullptr);
    TreeNode nodeOneOne(1, nullptr, &nodeOneTwo);

    // prints values of first traversal
    std::vector<int> traversalOne = inorderTraversal(&nodeOneOne);
    for (int value : traversalOne) {
        std::cout << value << ", ";
    }
    std::cout << "\n";

    // prints values of second traversal
    std::vector<int> traversalTwo = inorderTraversal(nullptr);
    for (int value : traversalTwo) {
        std::cout << value << ", ";
    }
    std::cout << "\n";

    TreeNode nodeThree(1);

    // prints values of first traversal
    std::vector<int> traversalThree = inorderTraversal(&nodeThree);
    for (int value : traversalThree) {
        std::cout << value << ", ";
    }
    std::cout << "\n";
}
