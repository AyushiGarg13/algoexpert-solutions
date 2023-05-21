#include <vector>
#include <queue>

using namespace std;

int oppositeColor(int color) { return color == 1 ? 2 : 1; }

bool twoColorable(vector<vector<int>> edges)
{

    vector<int> colorOfNodes(edges.size(), 0);
    queue<int> adjacent_nodes;
    adjacent_nodes.push(0);
    colorOfNodes[0] = 1;

    while (!adjacent_nodes.empty())
    {
        int front = adjacent_nodes.front();
        for (int i : edges[front])
        {
            if (colorOfNodes[i] == 0)
            {
                adjacent_nodes.push(i);
                colorOfNodes[i] = oppositeColor(colorOfNodes[front]);
            }
            else if (colorOfNodes[i] != oppositeColor(colorOfNodes[front]))
                return false;
        }
        adjacent_nodes.pop();
    }
    return true;
}
