#include <vector>
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

void helper(BinaryTree *node, int sum, vector<int> &output)
{
    if (node == nullptr)
        return;

    sum += node->value;
    if (node->left == nullptr && node->right == nullptr)
    {
        output.push_back(sum);
        return;
    }

    helper(node->left, sum, output);
    helper(node->right, sum, output);
}

vector<int> branchSums(BinaryTree *root)
{
    vector<int> output;
    helper(root, 0, output);
    return output;
}
