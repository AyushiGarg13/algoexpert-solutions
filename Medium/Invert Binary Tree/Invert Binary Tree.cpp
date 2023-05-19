#include <vector>
using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree)
{
    if (tree != nullptr)
    {
        swap(tree->left, tree->right);
        invertBinaryTree(tree->left);
        invertBinaryTree(tree->right);
    }
}
