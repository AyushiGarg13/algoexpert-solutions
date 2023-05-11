#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target)
{
    int left = 0, right = array.size() - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == target)
            return mid;
        else if (target < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
