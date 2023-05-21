#include <vector>
using namespace std;

int get_next_index(int index, vector<int> array)
{
    index += array[index];
    index = index % (int)array.size();
    return index < 0 ? array.size() + index : index;
}

bool hasSingleCycle(vector<int> array)
{
    int i = 0, count = 0;
    while (count < array.size())
    {
        if (count > 0 && i == 0)
            return false;
        i = get_next_index(i, array);
        count++;
    }
    return i == 0;
}
