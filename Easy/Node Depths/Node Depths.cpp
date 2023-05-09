// Average Case
// O(n)T, O(h)S
// n = no. of nodes in the tree
// h = height of the tree

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

void helper(BinaryTree *node, int depth, int &sum)
{
    if (node == nullptr)
        return;
    sum += depth;
    if (node->left == nullptr && node->right == nullptr)
        return;
    helper(node->left, depth + 1, sum);
    helper(node->right, depth + 1, sum);
}

int nodeDepths(BinaryTree *root)
{
    int sum = 0;
    helper(root, 0, sum);
    return sum;
}
