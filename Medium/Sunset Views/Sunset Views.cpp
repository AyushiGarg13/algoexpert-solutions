#include <vector>
#include <string>
using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction)
{
    int startIdx = direction == "EAST" ? buildings.size() - 1 : 0;
    int step = direction == "EAST" ? -1 : 1;
    vector<int> output;
    int maxHeight = 0;
    while (startIdx >= 0 && startIdx < buildings.size())
    {
        if (maxHeight < buildings[startIdx])
        {
            maxHeight = buildings[startIdx];
            output.push_back(startIdx);
        }
        startIdx += step;
    }
    if (direction == "EAST")
        reverse(output.begin(), output.end());
    return output;
}
