/**
 * 145. Binary Tree Postorder Traversal
 * 
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
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

void postorderTraversal(std::vector<int>& p_traversal, TreeNode* p_rootNode)
{
    if (!p_rootNode) {
        return;
    }

    postorderTraversal(p_traversal, p_rootNode->leftNode);
    postorderTraversal(p_traversal, p_rootNode->rightNode);

    // adds current node after exploring left and right children
    p_traversal.push_back(p_rootNode->value);
}

std::vector<int> postorderTraversal(TreeNode* p_rootNode)
{
    std::vector<int> traversal;
    postorderTraversal(traversal, p_rootNode);
    return traversal;
}

int main(void)
{
    TreeNode nodeOneThree(3);
    TreeNode nodeOneTwo(2, &nodeOneThree, nullptr);
    TreeNode nodeOneOne(1, nullptr, &nodeOneTwo);

    // prints values of first traversal
    std::vector<int> traversalOne = postorderTraversal(&nodeOneOne);
    for (int value : traversalOne) {
        std::cout << value << ", ";
    }
    std::cout << "\n";

    // prints values of second traversal
    std::vector<int> traversalTwo = postorderTraversal(nullptr);
    for (int value : traversalTwo) {
        std::cout << value << ", ";
    }
    std::cout << "\n";

    TreeNode nodeThree(1);

    // prints values of first traversal
    std::vector<int> traversalThree = postorderTraversal(&nodeThree);
    for (int value : traversalThree) {
        std::cout << value << ", ";
    }
    std::cout << "\n";
}
