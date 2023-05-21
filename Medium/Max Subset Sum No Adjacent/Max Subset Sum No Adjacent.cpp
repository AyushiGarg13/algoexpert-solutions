#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
    if (array.size() == 0)
        return 0;
    else if (array.size() == 1)
        return array[0];
    int second = array[0];
    int first = max(array[0], array[1]);
    for (int i = 2; i < array.size(); i++)
    {
        int currentSum = max(first, second + array[i]);
        second = first;
        first = currentSum;
    }
    return first;
}
