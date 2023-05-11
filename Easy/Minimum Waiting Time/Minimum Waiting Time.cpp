#include <algorithm>
#include <vector>
using namespace std;

int minimumWaitingTime(vector<int> queries)
{
    sort(queries.begin(), queries.end());
    int sum = 0;
    for (int i = 1; i < queries.size(); i++)
    {
        sum = sum + queries[i - 1] * (queries.size() - i);
    }
    return sum;
}
