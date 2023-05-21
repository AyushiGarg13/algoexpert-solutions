#include <vector>
using namespace std;

class AncestralTree
{
public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name)
    {
        this->name = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree *> descendants);
};

int findDepth(AncestralTree *topAncestor,
              AncestralTree *descendant)
{
    int depth = 0;
    while (descendant != topAncestor)
    {
        descendant = descendant->ancestor;
        depth++;
    }
    return depth;
}

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo)
{
    int depthOne = findDepth(topAncestor, descendantOne);
    int depthTwo = findDepth(topAncestor, descendantTwo);

    while (depthOne != depthTwo)
    {
        if (depthTwo > depthOne)
        {
            descendantTwo = descendantTwo->ancestor;
            depthTwo--;
        }
        else
        {
            descendantOne = descendantOne->ancestor;
            depthOne--;
        }
    }

    while (descendantOne != descendantTwo)
    {
        descendantOne = descendantOne->ancestor;
        descendantTwo = descendantTwo->ancestor;
    }

    return descendantOne;
}
