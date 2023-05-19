#include <vector>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value)
    {
        if (value < this->value)
        {
            if (left == nullptr)
                left = new BST(value);
            else
                left->insert(value);
        }
        else
        {
            if (right == nullptr)
                right = new BST(value);
            else
                right->insert(value);
        }
    }
};

BST *helper(vector<int> array, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    int newValue = array[mid];

    BST *root = new BST(newValue);

    root->left = helper(array, start, mid - 1);
    root->right = helper(array, mid + 1, end);
    return root;
}

BST *minHeightBst(vector<int> array)
{
    return helper(array, 0, array.size() - 1);
}
