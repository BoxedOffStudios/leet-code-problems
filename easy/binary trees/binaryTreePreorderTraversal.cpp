/**
 * 144. Binary Tree Preorder Traversal
 * 
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
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

void preorderTraversal(std::vector<int>& p_traversal, TreeNode* p_rootNode)
{
    if (!p_rootNode) {
        return;
    }

    // adds current node then explores left and then explores right
    p_traversal.push_back(p_rootNode->value);

    preorderTraversal(p_traversal, p_rootNode->leftNode);
    preorderTraversal(p_traversal, p_rootNode->rightNode);
}

std::vector<int> preorderTraversal(TreeNode* p_rootNode)
{
    std::vector<int> traversal;
    preorderTraversal(traversal, p_rootNode);
    return traversal;
}

int main(void)
{
    TreeNode nodeOneThree(3);
    TreeNode nodeOneTwo(2, &nodeOneThree, nullptr);
    TreeNode nodeOneOne(1, nullptr, &nodeOneTwo);

    // prints values of first traversal
    std::vector<int> traversalOne = preorderTraversal(&nodeOneOne);
    for (int value : traversalOne) {
        std::cout << value << ", ";
    }
    std::cout << "\n";

    // prints values of second traversal
    std::vector<int> traversalTwo = preorderTraversal(nullptr);
    for (int value : traversalTwo) {
        std::cout << value << ", ";
    }
    std::cout << "\n";

    TreeNode nodeThree(1);

    // prints values of first traversal
    std::vector<int> traversalThree = preorderTraversal(&nodeThree);
    for (int value : traversalThree) {
        std::cout << value << ", ";
    }
    std::cout << "\n";
}
