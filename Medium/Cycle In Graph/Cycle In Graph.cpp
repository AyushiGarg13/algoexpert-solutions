#include <vector>
using namespace std;

bool traverse_connected_vertices(vector<vector<int>> edges, int vertex,
                                 vector<int> &vertex_details)
{
    vertex_details[vertex] = 1;

    for (auto adjacent_vertices : edges[vertex])
    {
        if (vertex_details[adjacent_vertices] == 1)
            return true;
        if (vertex_details[adjacent_vertices] == 2)
            continue;
        bool contains_cycle = traverse_connected_vertices(edges, adjacent_vertices, vertex_details);
        if (contains_cycle)
            return true;
    }
    vertex_details[vertex] = 2;
    return false;
}

bool cycleInGraph(vector<vector<int>> edges)
{
    
    vector<int> vertex_details(edges.size());
    for (int i = 0; i < edges.size(); i++)
    {
        if (vertex_details[i] != 0)
            continue;
        bool contains_cycle = traverse_connected_vertices(edges, i, vertex_details);
        if (contains_cycle)
            return true;
    }
    return false;
}
