#include <vector>

using namespace std;

int bestSeat(vector<int> seats)
{
    int maxZeroes = 0, bestSeat = -1;
    for (int i = 0; i < seats.size(); i++)
    {
        int startIdx = i, endIdx = i;
        while (endIdx < seats.size() && seats[endIdx] == 0)
            endIdx++;

        if (endIdx - startIdx > maxZeroes)
        {
            maxZeroes = endIdx - startIdx;
            bestSeat = (endIdx - 1 + startIdx) / 2;
        }
        i = endIdx;
    }

    return bestSeat;
}
