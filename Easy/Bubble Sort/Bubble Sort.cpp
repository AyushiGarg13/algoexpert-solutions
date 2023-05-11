#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] > array[j])
                swap(array[i], array[j]);
        }
    }
    return array;
}
