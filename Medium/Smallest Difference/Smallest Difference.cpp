#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int pointerOne = 0, pointerTwo = 0, difference, smallestdiff = INT_MAX;
    vector<int> pair;
    while (pointerOne < arrayOne.size() && pointerTwo < arrayTwo.size())
    {
        int first_num = arrayOne[pointerOne];
        int second_num = arrayTwo[pointerTwo];
        difference = abs(first_num - second_num);
        if (difference == 0)
            return {first_num, second_num};
        else if (first_num < second_num)
            pointerOne++;
        else
            pointerTwo++;

        if (difference < smallestdiff)
        {
            pair = {first_num, second_num};
            smallestdiff = difference;
        }
    }
    return pair;
}
