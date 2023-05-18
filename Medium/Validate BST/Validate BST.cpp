#include <climits>
class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

bool helper(BST *tree, int min_value, int max_value)
{
    if (tree->value < min_value || tree->value >= max_value)
        return false;
    if (tree->left != nullptr && !helper(tree->left, min_value, tree->value))
        return false;
    if (tree->right != nullptr && !helper(tree->right, tree->value, max_value))
        return false;
    return true;
}

bool validateBst(BST *tree)
{
    return helper(tree, INT_MIN, INT_MAX);
}
