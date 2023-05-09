#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove)
{
    int left = 0, right = array.size() - 1;
    while (left <= right)
    {
        int left_elem = array[left];
        int right_elem = array[right];
        if (right_elem == toMove)
            right--;
        else if (left_elem == toMove)
        {
            array[left] = right_elem;
            array[right] = left_elem;
            left++;
            right--;
        }
        else
            left++;
    }
    return array;
}
