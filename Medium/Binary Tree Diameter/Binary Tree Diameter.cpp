#include <algorithm>
using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

struct TreeInfo
{
    int diameter;
    int height;
};

TreeInfo getTreeInfo(BinaryTree *tree)
{
    if (tree == nullptr)
        return TreeInfo{0, 0};

    TreeInfo leftTreeInfo = getTreeInfo(tree->left);
    TreeInfo rightTreeInfo = getTreeInfo(tree->right);

    int longestPathThroughRoot = leftTreeInfo.height + rightTreeInfo.height;
    int maxDiameter = max(leftTreeInfo.diameter, rightTreeInfo.diameter);
    int currentDiameter = max(longestPathThroughRoot, maxDiameter);
    int currentHeight = 1 + max(leftTreeInfo.height, rightTreeInfo.height);

    return TreeInfo{currentDiameter, currentHeight};
}

int binaryTreeDiameter(BinaryTree *tree)
{
    return getTreeInfo(tree).diameter;
}
