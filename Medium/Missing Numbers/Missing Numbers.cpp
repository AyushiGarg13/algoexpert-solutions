#include <vector>
#include <numeric>
using namespace std;

vector<int> missingNumbers(vector<int> nums)
{
    int total = 0;
    for (int i = 1; i <= nums.size() + 2; i++)
        total += i;

    total -= accumulate(nums.begin(), nums.end(), 0);
    int average = total / 2;
    int firstHalf = 0, secondHalf = 0;
    for (int num : nums)
    {
        if (num <= average)
            firstHalf += num;
        else
            secondHalf += num;
    }

    int expectedFirstHalf = 0;
    for (int i = 1; i <= average; i++)
        expectedFirstHalf += i;

    int expectedSecondHalf = 0;
    for (int i = average + 1; i <= nums.size() + 2; i++)
        expectedSecondHalf += i;

    return {expectedFirstHalf - firstHalf, expectedSecondHalf - secondHalf};
}