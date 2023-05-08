#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins)
{
    sort(coins.begin(), coins.end());
    int change_possible = 0;
    for (auto c : coins)
    {
        if (c > change_possible + 1)
            return change_possible + 1;
        else
            change_possible += c;
    }
    return change_possible + 1;
}
