#include <vector>
using namespace std;

void changesTheOnesConnectedToBorder(int row, int column, vector<vector<int>> &matrix)
{
    if (row < 0 || column < 0 || row >= matrix.size() ||
        column >= matrix[row].size() || matrix[row][column] != 1)
        return;
    matrix[row][column] *= -1;
    changesTheOnesConnectedToBorder(row - 1, column, matrix);
    changesTheOnesConnectedToBorder(row, column - 1, matrix);
    changesTheOnesConnectedToBorder(row + 1, column, matrix);
    changesTheOnesConnectedToBorder(row, column + 1, matrix);
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            bool isBorder = i == 0 || j == 0 || i == matrix.size() - 1 || j == matrix[i].size() - 1;
            if (!isBorder || matrix[i][j] != 1)
                continue;
            changesTheOnesConnectedToBorder(i, j, matrix);
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1;
            else if (matrix[i][j] == 1)
                matrix[i][j] = 0;
        }
    }
    return matrix;
}
