/**
 * 94. Binary Tree Inorder Traversal
 * 
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 
 */

#include <vector>
#include <stack>
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

std::vector<int> inorderTraversal(TreeNode* p_rootNode)
{
    std::vector<int> traversal;
    std::stack<TreeNode*> nodesToTraverse;

    // finished traversal if both children are null and there is nothing on the stack left to traverse
    auto nodesRemaining = [&]() -> bool
    {
        return (p_rootNode->leftNode ||
                p_rootNode->rightNode ||
                nodesToTraverse.size() > 0);
    };

    while (p_rootNode && nodesRemaining()) {
        TreeNode* leftNode = p_rootNode->leftNode;

        // explores left node
        if (leftNode) {
            // ensures left node isn't searched again when traversing
            p_rootNode->leftNode = nullptr;
            nodesToTraverse.push(p_rootNode);

            p_rootNode = leftNode;
            continue;
        }

        traversal.emplace_back(p_rootNode->value);

        TreeNode* rightNode = p_rootNode->rightNode;

        // explores right node
        if (rightNode) {
            p_rootNode = rightNode;
            continue;
        }

        // current node has no children (leaf node) - checks for nodes to traverse on the stack
        p_rootNode = nodesToTraverse.top();
        nodesToTraverse.pop();
    }

    // adds final node from stack
    if (p_rootNode != nullptr) {
        traversal.emplace_back(p_rootNode->value);
    }

    return traversal;
}

int main(void)
{
    TreeNode nodeOneThree(1);
    TreeNode nodeOneTwo(3, &nodeOneThree, nullptr);
    TreeNode nodeOneOne(2, &nodeOneTwo, nullptr);

    std::vector<int> traversalOne = inorderTraversal(&nodeOneOne);

    // prints values from first inorder traversal
    for (int value : traversalOne) {
        std::cout << value << ", ";
    }

    std::cout << "\n";

    std::vector<int> traversalTwo = inorderTraversal(nullptr);

    // prints values from second inorder traversal
    for (int value : traversalTwo) {
        std::cout << value << ", ";
    }

    std::cout << "\n";

    TreeNode nodeThreeThree(1);

    std::vector<int> traversalThree = inorderTraversal(&nodeThreeThree);

    // prints values from second inorder traversal
    for (int value : traversalThree) {
        std::cout << value << ", ";
    }

    std::cout << "\n";
}
