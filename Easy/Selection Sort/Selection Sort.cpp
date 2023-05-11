#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        int smallest = i;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[smallest])
                smallest = j;
        }
        swap(array[smallest], array[i]);
    }
    return array;
}
