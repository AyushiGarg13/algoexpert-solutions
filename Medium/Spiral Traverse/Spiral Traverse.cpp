#include <vector>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array)
{
    int startrow = 0, endrow = array.size() - 1;
    int startcol = 0, endcol = array[0].size() - 1;
    vector<int> result;

    while (startrow <= endrow && startcol <= endcol)
    {
        for (int i = startcol; i <= endcol; i++)
            result.push_back(array[startrow][i]);

        for (int i = startrow + 1; i <= endrow; i++)
            result.push_back(array[i][endcol]);

        for (int i = endcol - 1; i >= startcol; i--)
        {
            if (startrow == endrow)
                break;
            result.push_back(array[endrow][i]);
        }
        for (int i = endrow - 1; i >= startrow + 1; i--)
        {
            if (startcol == endcol)
                break;
            result.push_back(array[i][startcol]);
        }
        startrow++;
        endrow--;
        startcol++;
        endcol--;
    }
    return result;
}
