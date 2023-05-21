using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;
    BinaryTree *parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree *findLeftmostChildOfTheRightSubtree(BinaryTree *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

BinaryTree *findRightmostParentwhereNodeisaleftChild(BinaryTree *node)
{
    while (node->parent != nullptr && node->parent->right == node)
        node = node->parent;
    return node->parent;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node)
{
    if (node->right != nullptr)
        return findLeftmostChildOfTheRightSubtree(node->right);
    return findRightmostParentwhereNodeisaleftChild(node);
}
