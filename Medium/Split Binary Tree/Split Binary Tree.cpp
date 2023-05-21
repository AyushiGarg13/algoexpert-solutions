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
    int sum;
    bool canBeSplit;
};

int getTreeSum(BinaryTree *tree)
{
    if (tree == nullptr)
        return 0;
    return getTreeSum(tree->left) + getTreeSum(tree->right) + tree->value;
}

TreeInfo findSubtreeSums(BinaryTree *tree, int desiredSum)
{
    if (tree == nullptr)
        return TreeInfo{0, false};

    TreeInfo leftSubTree = findSubtreeSums(tree->left, desiredSum);
    TreeInfo rightSubTree = findSubtreeSums(tree->right, desiredSum);

    int currentSum = tree->value + leftSubTree.sum + rightSubTree.sum;
    bool currentSplit = leftSubTree.canBeSplit || rightSubTree.canBeSplit || currentSum == desiredSum;
    return TreeInfo{currentSum, currentSplit};
}

int splitBinaryTree(BinaryTree *tree)
{
    int totalSum = getTreeSum(tree);
    if (totalSum % 2 != 0)
        return 0;
    int desiredSum = totalSum / 2;
    return findSubtreeSums(tree, desiredSum).canBeSplit ? desiredSum : 0;
}
