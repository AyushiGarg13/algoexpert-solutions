#include <vector>
using namespace std;

void permutationsHelper(int i, vector<int> array, vector<vector<int>> &permutations)
{
    if (i == array.size() - 1)
        permutations.push_back(array);
    else
    {
        for (int j = i; j < array.size(); j++)
        {
            swap(array[i], array[j]);
            permutationsHelper(i + 1, array, permutations);
            swap(array[i], array[j]);
        }
    }
}

vector<vector<int>> getPermutations(vector<int> array)
{

    vector<vector<int>> permutations;
    permutationsHelper(0, array, permutations);
    return permutations;
}
