#include <any>
#include <vector>

using namespace std;

int helper(vector<any> array, int level)
{
    int sum = 0;
    for (auto element : array)
    {
        if (element.type() == typeid(int))
            sum += any_cast<int>(element);
        else
            sum += helper(any_cast<vector<any>>(element), level + 1);
    }
    return sum * level;
}

int productSum(vector<any> array)
{
    int sum = 0;
    sum = helper(array, 1);
    return sum;
}
