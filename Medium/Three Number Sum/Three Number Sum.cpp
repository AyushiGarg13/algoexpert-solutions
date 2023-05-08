#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
    sort(array.begin(), array.end());
    vector<vector<int>> result;
    int left, right;
    for (int i = 0; i < array.size() - 2; i++)
    {
        left = i + 1;
        right = array.size() - 1;
        while (left < right)
        {
            if (array[left] + array[i] + array[right] == targetSum)
            {
                result.push_back({array[i], array[left], array[right]});
                left++;
                right--;
            }
            else if (array[left] + array[i] + array[right] < targetSum)
                left++;
            else
                right--;
        }
    }
    return result;
}
