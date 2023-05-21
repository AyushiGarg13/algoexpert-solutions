#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array)
{
    int maxSoFar = array[0], maxEndingAtThisIndex = array[0];
    for (int i = 1; i < array.size(); i++)
    {
        maxEndingAtThisIndex = max(array[i], maxEndingAtThisIndex + array[i]);
        maxSoFar = max(maxSoFar, maxEndingAtThisIndex);
    }
    return maxSoFar;
}
