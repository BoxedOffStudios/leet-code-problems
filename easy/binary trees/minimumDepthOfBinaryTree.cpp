/**
 * 111. Minimum Depth of Binary Tree
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
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

int minDepth(TreeNode* p_tree)
{
    if (p_tree == nullptr) {
        return 0;
    }

    // tree only has one child and therefore, this becomes the minimum depth
    if (p_tree->leftNode && !p_tree->rightNode) {
        return 1 + minDepth(p_tree->leftNode);
    }

    if (!p_tree->leftNode && p_tree->rightNode) {
        return 1 + minDepth(p_tree->rightNode);
    }

    // otherwise, minimum depth of tree is minimum depths of both of children's sub-trees
    return 1 + std::min(minDepth(p_tree->leftNode),
                        minDepth(p_tree->rightNode));
}

int main(void)
{
    TreeNode nodeOneFive(7);
    TreeNode nodeOneFour(15);
    TreeNode nodeOneThree(20, &nodeOneFour, &nodeOneFive);
    TreeNode nodeOneTwo(9);
    TreeNode nodeOneOne(3, &nodeOneTwo, &nodeOneThree);

    std::cout << minDepth(&nodeOneOne) << "\n";
}
