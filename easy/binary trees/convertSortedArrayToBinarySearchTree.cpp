/**
 * 108. Convert Sorted Array to Binary Search Tree
 *
 * Given an integer array 'p_numbers' where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree.
 *
 */

#include <vector>
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

void destroyHeapAllocatedTree(TreeNode* p_tree)
{
    if (!p_tree) {
        return;
    }

    destroyHeapAllocatedTree(p_tree->leftNode);
    destroyHeapAllocatedTree(p_tree->rightNode);

    delete p_tree;
}

TreeNode* sortedArrayToBST(const std::vector<int>& p_numbers)
{
    // empty array should not create a tree
    if (p_numbers.size() == 0) {
        return nullptr;
    }

    // reached leaf node
    if (p_numbers.size() == 1) {
        TreeNode* leafNode = new TreeNode(p_numbers.at(0));
        return leafNode;
    }

    auto getNumbersPartition = [&p_numbers](size_t startIndex, size_t endIndex) -> std::vector<int>
    {
        auto begin = std::next(p_numbers.begin(), startIndex);
        auto end = std::next(p_numbers.begin(), endIndex);
        return std::vector<int>(begin, end);
    };

    // splits numbers in half to form two partitions
    size_t indexMiddle = p_numbers.size() / 2U;
    std::vector<int> leftPartition = getNumbersPartition(0, indexMiddle);
    std::vector<int> rightPartition = getNumbersPartition(indexMiddle + 1, p_numbers.size());

    // recurses into both the left and the right parition to determine the immediate children
    TreeNode* leftChild = sortedArrayToBST(leftPartition);
    TreeNode* rightChild = sortedArrayToBST(rightPartition);

    return new TreeNode(p_numbers.at(indexMiddle), leftChild, rightChild);
}

int main(void)
{
    std::vector<int> testOne = {-10, -3, 0, 5, 9 };
    TreeNode* sortedOne = sortedArrayToBST(testOne);
    destroyHeapAllocatedTree(sortedOne);

    std::vector<int> testTwo = { 1, 3 };
    TreeNode* sortedTwo = sortedArrayToBST(testTwo);
    destroyHeapAllocatedTree(sortedTwo);
}
