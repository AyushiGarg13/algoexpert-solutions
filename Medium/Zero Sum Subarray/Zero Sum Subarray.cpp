#include <vector>
#include <unordered_set>
using namespace std;

bool zeroSumSubarray(vector<int> nums)
{
    unordered_set<int> findsame = {0};
    int current_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        current_sum += nums[i];
        if (findsame.find(current_sum) != findsame.end())
            return true;
        findsame.insert(current_sum);
    }
    return false;
}
