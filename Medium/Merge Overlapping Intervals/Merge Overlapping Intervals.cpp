#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);
    int oi = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= output[oi][1])
        {
            auto elem = {output[oi][0], max(output[oi][1], intervals[i][1])};
            output.pop_back();
            output.push_back(elem);
        }
        else
        {
            output.push_back(intervals[i]);
            oi++;
        }
    }
    return output;
}
