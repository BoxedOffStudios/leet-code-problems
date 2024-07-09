/** 
 * 100. Same Tree
 * 
 * Given the roots of two binary trees 'p_firstRoot' and 'p_secondRoot', write a function to check if they are the same or not.
 * 
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * 
 */

#include <utility>
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

bool isSameTree(TreeNode* p_firstRoot, TreeNode* p_secondRoot)
{
    using TreeNodePair = std::pair<TreeNode*, TreeNode*>;

    auto isPairMatching = [](const TreeNodePair& p_treeNodePair) -> bool
    {
        // both are null - matching
        if (p_treeNodePair.first == nullptr && p_treeNodePair.second == nullptr) {
            return true;
        }

        // only one of the pair is null - NOT matching
        if (p_treeNodePair.first == nullptr || p_treeNodePair.second == nullptr) {
            return false;
        }

        return p_treeNodePair.first->value == p_treeNodePair.second->value;
    };

    std::queue<TreeNodePair> pairsToCheck;

    // adds both left nodes and then both right nodes as two separate pairs
    auto addChildrenToQueue = [&pairsToCheck](TreeNodePair p_parents) -> void
    {
        if (p_parents.first->leftNode != nullptr || p_parents.second->leftNode != nullptr) {
            pairsToCheck.emplace(p_parents.first->leftNode, p_parents.second->leftNode);
        }

        if (p_parents.first->rightNode != nullptr || p_parents.second->rightNode != nullptr) {
            pairsToCheck.emplace(p_parents.first->rightNode, p_parents.second->rightNode);
        }
    };
    
    // begins by adding the root parents to be checked
    if (p_firstRoot != nullptr || p_secondRoot != nullptr) {
        pairsToCheck.emplace(p_firstRoot, p_secondRoot);
    }

    while (!pairsToCheck.empty()) {
        TreeNodePair currentPair = pairsToCheck.front();
        pairsToCheck.pop();

        if (!isPairMatching(currentPair)) {
            return false;
        }

        // pair is matching
        addChildrenToQueue(currentPair);
    }

    return true;
}

int main(void)
{
    TreeNode nodeOneThree(3);
    TreeNode nodeOneTwo(2);
    TreeNode nodeOneOne(1, &nodeOneTwo, &nodeOneThree);

    TreeNode nodeTwoThree(3);
    TreeNode nodeTwoTwo(2);
    TreeNode nodeTwoOne(1, &nodeTwoTwo, &nodeTwoThree);

    std::cout << (isSameTree(&nodeOneOne, &nodeTwoOne) ? "true" : "false") << "\n";
}
