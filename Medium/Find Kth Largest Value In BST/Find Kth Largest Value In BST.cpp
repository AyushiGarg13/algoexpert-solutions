using namespace std;
class BST
{
public:
    int value;
    BST *left = nullptr;
    BST *right = nullptr;

    BST(int value) { this->value = value; }
};

void traversalHelper(BST *node, int &counter, int k, int &answer)
{
    if (node != nullptr && counter <= k)
    {
        traversalHelper(node->right, counter, k, answer);
        counter++;
        if (counter == k)
            answer = node->value;
        traversalHelper(node->left, counter, k, answer);
    }
}

int findKthLargestValueInBst(BST *tree, int k)
{
    int ans, counter = 0;
    traversalHelper(tree, counter, k, ans);
    return ans;
}
