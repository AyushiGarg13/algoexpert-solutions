#include <vector>
#include <math.h>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
    // Write your code here.
    int index = array.size() - 1;
    vector<int> output(index + 1);
    int small = 0, large = index;
    while (small <= large)
    {
        if (abs(array[small]) >= abs(array[large]))
        {
            output[index] = array[small] * array[small];
            small++;
        }
        else
        {
            output[index] = array[large] * array[large];
            large--;
        }
        index--;
    }
    return output;
}
