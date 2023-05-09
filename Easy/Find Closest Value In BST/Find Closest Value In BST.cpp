#include <math.h>
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

int findClosestValueInBst(BST *tree, int target)
{
    BST *currentnode = tree, *least_diffnode = tree;
    int least_difference = INT_MAX;
    while (currentnode != nullptr)
    {
        int current_difference = target - (currentnode->value);
        if (abs(least_difference) > abs(current_difference))
        {
            least_difference = current_difference;
            least_diffnode = currentnode;
        }
        if (current_difference == 0)
            return currentnode->value;
        else if (current_difference > 0)
            currentnode = currentnode->right;
        else
            currentnode = currentnode->left;
    }
    return least_diffnode->value;
}
