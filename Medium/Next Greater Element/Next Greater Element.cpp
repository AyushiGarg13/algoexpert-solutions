#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> array)
{
    stack<int> idxStack;
    vector<int> output(array.size(), -1);
    for (int i = 0; i < 2 * array.size(); i++)
    {
        int idx = i % array.size();
        while (!idxStack.empty() && array[idx] > array[idxStack.top()])
        {
            output[idxStack.top()] = array[idx];
            idxStack.pop();
        }
        idxStack.push(idx);
    }

    return output;
}
