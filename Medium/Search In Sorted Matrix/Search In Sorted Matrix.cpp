#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target)
{
    int row = 0, column = matrix[0].size() - 1;
    while (row < matrix.size() && column >= 0)
    {
        if (matrix[row][column] == target)
            return {row, column};
        else if (matrix[row][column] > target)
            column--;
        else
            row++;
    }
    return {-1, -1};
}
