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

BinaryTree *mergeBinaryTrees(BinaryTree *tree1, BinaryTree *tree2)
{
    if (tree1 != nullptr && tree2 != nullptr)
    {
        tree1->value += tree2->value;
        if (tree1->left == nullptr && tree2->left != nullptr)
            tree1->left = tree2->left;
        else
            mergeBinaryTrees(tree1->left, tree2->left);
        if (tree1->right == nullptr && tree2->right != nullptr)
            tree1->right = tree2->right;
        else
            mergeBinaryTrees(tree1->right, tree2->right);
    }
    if (tree1 == nullptr && tree2 != nullptr)
        tree1 = tree2;
    return tree1;
}

BinaryTree *mergeBinaryTrees(BinaryTree *tree1, BinaryTree *tree2)
{
    if (tree1 == nullptr)
        return tree2;
    if (tree2 == nullptr)
        return tree1;
    tree1->value += tree2->value;
    tree1->left = mergeBinaryTrees(tree1->left, tree2->left);
    tree1->right = mergeBinaryTrees(tree1->right, tree2->right);
    return tree1;
}