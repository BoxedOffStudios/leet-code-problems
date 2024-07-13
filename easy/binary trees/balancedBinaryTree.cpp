/**
 * 110. Balanced Binary Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 */

#include <unordered_map>
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

std::unordered_map<TreeNode*, int> treeHeightMap = { { nullptr, 0 } };

int getTreeHeight(TreeNode* p_tree)
{
    // checks height map first
    if (treeHeightMap.find(p_tree) != treeHeightMap.end()) {
        return treeHeightMap.at(p_tree);
    }

    // height is the maximum height out of both of the children's sub-trees
    int height = 1 + std::max(getTreeHeight(p_tree->leftNode), getTreeHeight(p_tree->rightNode));
    treeHeightMap.insert({ p_tree, height });
    return height;
}

bool isBalanced(TreeNode* p_tree)
{
    if (p_tree == nullptr) {
        return true;
    }

    // determines the height difference between the two children's sub-trees
    int heightDifferenceChildren = abs(getTreeHeight(p_tree->leftNode) - getTreeHeight(p_tree->rightNode));

    if (heightDifferenceChildren > 1) {
        return false;
    }

    // tree is only balanced if its children's sub-trees are balanced
    return isBalanced(p_tree->leftNode) && isBalanced(p_tree->rightNode);
}

int main(void)
{
    TreeNode nodeOneFive(7);
    TreeNode nodeOneFour(15);
    TreeNode nodeOneThree(20, &nodeOneFour, &nodeOneFive);
    TreeNode nodeOneTwo(9);
    TreeNode nodeOneOne(3, &nodeOneTwo, &nodeOneThree);

    std::cout << (isBalanced(&nodeOneOne) ? "true" : "false") << "\n";
}
