#include <vector>
#include <queue>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector<string> breadthFirstSearch(vector<string> *array)
    {
        queue<Node *> helper;
        helper.push(this);
        while (!helper.empty())
        {
            auto current = helper.front();
            helper.pop();
            array->push_back(current->name);
            for (Node *child : current->children)
                helper.push(child);
        }
        return *array;
    }

    Node *addChild(string name)
    {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
