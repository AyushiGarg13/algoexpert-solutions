#include <vector>
#include <climits>
using namespace std;

void shift(vector<int> &output, int value, int index)
{
    for (int i = 0; i <= index; i++)
    {
        if (i == index)
            output[index] = value;
        else
            output[i] = output[i + 1];
    }
}

vector<int> findThreeLargestNumbers(vector<int> array)
{
    vector<int> output(3, INT_MIN);
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > output[2])
            shift(output, array[i], 2);
        else if (array[i] > output[1])
            shift(output, array[i], 1);
        else if (array[i] > output[0])
            shift(output, array[i], 0);
    }
    return output;
}
