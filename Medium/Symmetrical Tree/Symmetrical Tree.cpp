using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value)
    {
        this->value = value;
    }
};

bool traverseTree(BinaryTree *leftTree, BinaryTree *rightTree)
{

    if (leftTree != nullptr && rightTree != nullptr && leftTree->value == rightTree->value)
        return traverseTree(leftTree->left, rightTree->right) &&
               traverseTree(leftTree->right, rightTree->left);

    return leftTree == rightTree;
}

bool symmetricalTree(BinaryTree *tree)
{
    return traverseTree(tree->left, tree->right);
}
