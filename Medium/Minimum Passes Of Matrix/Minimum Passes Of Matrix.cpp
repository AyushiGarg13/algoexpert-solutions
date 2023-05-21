#include <vector>
#include <queue>
using namespace std;

struct index
{
    int row;
    int column;
};

vector<index> get_neighbours(index node)
{
    return {
        index{node.row - 1, node.column},
        index{node.row, node.column - 1},
        index{node.row + 1, node.column},
        index{node.row, node.column + 1},
    };
}

int minimumPassesOfMatrix(vector<vector<int>> matrix)
{
    
    queue<index> positive_queue;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] > 0)
                positive_queue.push(index{i, j});
        }
    }
    int current_size = positive_queue.size(), next_size = 0, passes = 0;
    while (!positive_queue.empty())
    {
        index node = positive_queue.front();
        auto neighbours = get_neighbours(node);
        for (auto nb : neighbours)
        {
            if (nb.row < 0 || nb.column < 0 || nb.row >= matrix.size() ||
                nb.column >= matrix[nb.row].size() || matrix[nb.row][nb.column] >= 0)
                continue;
            else
            {
                matrix[nb.row][nb.column] *= -1;
                positive_queue.push(nb);
                next_size++;
            }
        }
        positive_queue.pop();
        current_size--;

        if (current_size == 0)
        {
            swap(current_size, next_size);
            passes++;
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] < 0)
                return -1;
        }
    }
    return passes - 1;
}
