#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int denom : denoms)
    {
        for (int amount = 1; amount < ways.size(); amount++)
        {
            if (denom <= amount)
                ways[amount] += ways[amount - denom];
        }
    }
    return ways[n];
}
