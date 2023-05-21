#include <math.h>
#include <algorithm>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

struct TreeInfo
{
    int height;
    bool balanced;
};

TreeInfo getTreeInfo(BinaryTree *node)
{
    if (node == nullptr)
        return TreeInfo{-1, true};

    auto leftTreeInfo = getTreeInfo(node->left);
    auto rightTreeInfo = getTreeInfo(node->right);

    bool balanceOfNode = abs(leftTreeInfo.height - rightTreeInfo.height) > 1 ? false : true;
    int currentHeight = 1 + max(leftTreeInfo.height, rightTreeInfo.height);
    bool currentBalance = balanceOfNode && leftTreeInfo.balanced && rightTreeInfo.balanced;

    return TreeInfo{currentHeight, currentBalance};
}

bool heightBalancedBinaryTree(BinaryTree *tree)
{
    return getTreeInfo(tree).balanced;
}
