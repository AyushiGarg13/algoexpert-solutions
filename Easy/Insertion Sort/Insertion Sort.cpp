#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array)
{
    for (int i = 1; i < array.size(); i++)
    {
        int j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
    return array;
}
