#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order)
{
    
    int first = 0, second = 0, third = array.size() - 1;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[second] == order[1])
            second++;
        else if (array[second] == order[0])
        {
            swap(array[first], array[second]);
            first++;
            second++;
        }
        else
        {
            swap(array[third], array[second]);
            third--;
        }
    }
    return array;
}
