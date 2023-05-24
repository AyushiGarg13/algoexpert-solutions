#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array)
{

    vector<vector<int>> subsets = {{}};
    for (int i = 0; i < array.size(); i++)
    {
        int subsetsSize = subsets.size();
        for (int j = 0; j < subsetsSize; j++)
        {
            vector<int> itemToPush = subsets[j];
            itemToPush.push_back(array[i]);
            subsets.push_back(itemToPush);
        }
    }
    return subsets;
}
