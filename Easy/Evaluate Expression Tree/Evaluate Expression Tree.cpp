using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree *tree)
{
    if (tree->left == nullptr && tree->right == nullptr)
        return tree->value;
    switch (tree->value)
    {
    case -1:
        return evaluateExpressionTree(tree->left) + evaluateExpressionTree(tree->right);
    case -2:
        return evaluateExpressionTree(tree->left) - evaluateExpressionTree(tree->right);
    case -3:
        return evaluateExpressionTree(tree->left) / evaluateExpressionTree(tree->right);
    case -4:
        return evaluateExpressionTree(tree->left) * evaluateExpressionTree(tree->right);
    }
}
