#include <climits>
#include <vector>
using namespace std;

class BST
{
public:
    int value;
    BST *left = nullptr;
    BST *right = nullptr;

    BST(int value) { this->value = value; }
};

BST *helper(int &index, vector<int> array, int minBound, int maxBound)
{
    if (index < array.size() && array[index] >= minBound && array[index] < maxBound)
    {
        BST *bst = new BST(array[index]);
        index++;

        bst->left = helper(index, array, minBound, bst->value);
        bst->right = helper(index, array, bst->value, maxBound);

        return bst;
    }
    return nullptr;
}

BST *reconstructBst(vector<int> preOrderTraversalValues)
{
    int index = 0;
    return helper(index, preOrderTraversalValues, INT_MIN, INT_MAX);
}
