#include <vector>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST &insert(int val)
    {
        BST *currentnode = this;
        while (true)
        {
            if (val < currentnode->value)
            {
                if (currentnode->left == nullptr)
                {
                    BST *newnode = new BST(val);
                    currentnode->left = newnode;
                    break;
                }
                else
                {
                    currentnode = currentnode->left;
                }
            }
            else
            {
                if (currentnode->right == nullptr)
                {
                    BST *newnode = new BST(val);
                    currentnode->right = newnode;
                    break;
                }
                else
                {
                    currentnode = currentnode->right;
                }
            }
        }
        return *this;
    }

    bool contains(int val)
    {
        BST *currentnode = this;
        while (currentnode != nullptr)
        {
            if (val == currentnode->value)
                return true;
            else if (val < currentnode->value)
                currentnode = currentnode->left;
            else
                currentnode = currentnode->right;
        }
        return false;
    }

    int getminval()
    {
        BST *currentnode = this;
        while (currentnode->left != nullptr)
            currentnode = currentnode->left;
        return currentnode->value;
    }

    BST &remove(int val, BST *parentnode = nullptr)
    {
        BST *currentnode = this;
        while (currentnode != nullptr)
        {
            if (val < currentnode->value)
            {
                parentnode = currentnode;
                currentnode = currentnode->left;
            }
            else if (val > currentnode->value)
            {
                parentnode = currentnode;
                currentnode = currentnode->right;
            }
            else
            {
                if (currentnode->left != nullptr && currentnode->right != nullptr)
                {
                    currentnode->value = currentnode->right->getminval();
                    currentnode->right->remove(currentnode->value, currentnode);
                }
                else if (parentnode == nullptr)
                {
                    if (currentnode->left != nullptr)
                    {
                        currentnode->value = currentnode->left->value;
                        currentnode->right = currentnode->left->right;
                        currentnode->left = currentnode->left->left;
                    }
                    else if (currentnode->right != nullptr)
                    {
                        currentnode->value = currentnode->right->value;
                        currentnode->left = currentnode->right->left;
                        currentnode->right = currentnode->right->right;
                    }
                    else
                        currentnode = nullptr;
                }
                else if (parentnode->left == currentnode)
                    parentnode->left = currentnode->left != nullptr ? currentnode->left : currentnode->right;
                else if (parentnode->right == currentnode)
                    parentnode->right = currentnode->left != nullptr ? currentnode->left : currentnode->right;
                break;
            }
        }
        return *this;
    }
};
