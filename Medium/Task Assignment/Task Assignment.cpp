#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, vector<int>> assignIndices(vector<int> tasks)
{
    unordered_map<int, vector<int>> indexMap;
    for (int i = 0; i < tasks.size(); i++)
        indexMap[tasks[i]].push_back(i);

    return indexMap;
}

vector<vector<int>> taskAssignment(int k, vector<int> tasks)
{
    vector<int> sorted_tasks = tasks;
    unordered_map<int, vector<int>> indexMap = assignIndices(tasks);
    sort(sorted_tasks.begin(), sorted_tasks.end());
    vector<vector<int>> output;
    int left = 0, right = tasks.size() - 1;

    while (left < right)
    {
        int task1 = indexMap[sorted_tasks[left]].back();
        indexMap[sorted_tasks[left]].pop_back();
        int task2 = indexMap[sorted_tasks[right]].back();
        indexMap[sorted_tasks[right]].pop_back();
        output.push_back({task1, task2});
        left++;
        right--;
    }
    return output;
}
