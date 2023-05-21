#include <vector>
using namespace std;

int numberOfWaysToTraverseGraph(int width, int height)
{
    vector<vector<int>> matrix(height, vector<int>(width));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 1;
            else
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }
    return matrix[height - 1][width - 1];
}
