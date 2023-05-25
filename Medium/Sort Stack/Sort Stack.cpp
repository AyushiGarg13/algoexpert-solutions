#include <vector>
using namespace std;

void insert(vector<int> &stack, int element)
{
    if (stack.empty() || element > stack.back())
    {
        stack.push_back(element);
        return;
    }

    int elem = stack.back();
    stack.pop_back();
    insert(stack, element);
    stack.push_back(elem);
    return;
}

vector<int> sortStack(vector<int> &stack)
{
    if (stack.size() <= 0)
        return stack;

    int top = stack.back();
    stack.pop_back();
    sortStack(stack);
    insert(stack, top);
    return stack;
}
