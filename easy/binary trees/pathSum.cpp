/**
 * 112. Path Sum
 *
 * Given the root of a binary tree and an integer 'p_targetSum', return true if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals 'p_targetSum'.
 * 
 * A leaf is a node with no children.
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

bool hasPathSum(TreeNode* p_tree, int p_targetSum)
{
    if (p_tree == nullptr)
    {
        return false;
    }

    // checks whether leaf has reached the target sum
    if (!p_tree->leftNode && !p_tree->rightNode &&
        p_targetSum == p_tree->value)
    {
        return true;
    }

    // if either of the children can make the target sum minus the current node's value,
    // then the target sum can be achieved by including the current node in the path
    return (hasPathSum(p_tree->leftNode, p_targetSum - p_tree->value)
            || hasPathSum(p_tree->rightNode, p_targetSum - p_tree->value));
}

int main(void)
{
    TreeNode nodeNine(1);
    TreeNode nodeEight(2);
    TreeNode nodeSeven(7);
    TreeNode nodeSix(4, nullptr, &nodeNine);
    TreeNode nodeFive(13);
    TreeNode nodeFour(11, &nodeSeven, &nodeEight);
    TreeNode nodeThree(8, &nodeFive, &nodeSix);
    TreeNode nodeTwo(4, &nodeFour, nullptr);
    TreeNode nodeOne(5, &nodeTwo, &nodeThree);

    std::cout << (hasPathSum(&nodeOne, 22) ? "true" : "false") << "\n";
}
