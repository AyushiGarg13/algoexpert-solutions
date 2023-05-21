#include <vector>
#include <climits>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
    vector<int> minCoins(n + 1, INT_MAX);
    minCoins[0] = 0;
    for (int denom : denoms)
    {
        for (int amount = 1; amount < n + 1; amount++)
        {
            int toCompare = minCoins[amount - denom] == INT_MAX ? minCoins[amount - denom] : minCoins[amount - denom] + 1;
            if (denom <= amount)
                minCoins[amount] = min(minCoins[amount], toCompare);
        }
    }
    return minCoins[n] == INT_MAX ? -1 : minCoins[n];
}
