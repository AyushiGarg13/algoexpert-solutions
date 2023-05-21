// Time = O(w*h), w = width of matrix, h = height of matrix
// Space = O(k), k = length of longest river, at most it can be (w*h)
// if matrix is completely filled with 1s.

// Another solution: keeping a matrix of same size as the size of origin matrix, having boolean values.
// Marking whether node -> i,j has been visited or not.

// Need to know whether the matrix is mutable or not.

#include <vector>
using namespace std;

void findSizeOfTheRiver(int row, int column, int &size, vector<vector<int>> &matrix)
{
    if (row < 0 || column < 0 || row >= matrix.size() ||
        column >= matrix[row].size() || matrix[row][column] != 1)
        return;
    size++;
    matrix[row][column] *= -1;
    findSizeOfTheRiver(row - 1, column, size, matrix);
    findSizeOfTheRiver(row, column - 1, size, matrix);
    findSizeOfTheRiver(row + 1, column, size, matrix);
    findSizeOfTheRiver(row, column + 1, size, matrix);
}

vector<int> riverSizes(vector<vector<int>> matrix)
{
    
    vector<int> output;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] != 1)
                continue;
            int size = 0;
            findSizeOfTheRiver(i, j, size, matrix);
            output.push_back(size);
        }
    }
    return output;
}
