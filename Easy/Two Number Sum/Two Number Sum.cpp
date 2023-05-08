#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    // Write your code here.
    unordered_set<int> nums;
    for (int i = 0; i < array.size(); i++)
    {
        if (nums.find(targetSum - array[i]) != nums.end())
            return {array[i], targetSum - array[i]};
        nums.insert(array[i]);
    }
    return {};
}
