#include <vector>
using namespace std;

int staircaseTraversal(int height, int maxSteps)
{
    vector<int> ways(height + 1, 1);
    int currentSum = 1;
    for (int i = 2; i <= height; i++)
    {
        int outOfBoundVal = (i - maxSteps - 1) < 0 ? 0 : ways[i - maxSteps - 1];
        ways[i] = currentSum + ways[i - 1] - outOfBoundVal;
        currentSum = ways[i];
    }

    return ways[height];
}
