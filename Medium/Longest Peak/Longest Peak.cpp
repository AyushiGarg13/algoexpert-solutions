#include <vector>
using namespace std;

int longestPeak(vector<int> array)
{
    int longestpeaklen = 0;
    int i = 1;
    while (i < int(array.size() - 1))
    {
        bool ispeak = array[i] > array[i - 1] && array[i] > array[i + 1];
        if (!ispeak)
        {
            i++;
            continue;
        }

        int leftidx = i - 2;
        while (leftidx >= 0 && array[leftidx] < array[leftidx + 1])
            leftidx--;
        int rightidx = i + 2;
        while (rightidx < array.size() && array[rightidx] < array[rightidx - 1])
            rightidx++;
        int currentpeaklen = rightidx - leftidx - 1;
        longestpeaklen = max(longestpeaklen, currentpeaklen);
        i = rightidx;
    }
    return longestpeaklen;
}
