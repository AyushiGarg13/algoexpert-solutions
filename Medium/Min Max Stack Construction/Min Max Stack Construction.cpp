#include <vector>
using namespace std;

class MinMaxStack
{
public:
    vector<int> minMaxStack;
    vector<int> minStack;
    vector<int> maxStack;
    int peek()
    {
        return minMaxStack.back();
    }
    int pop()
    {
        int topValue = peek();
        if (!minMaxStack.empty())
        {
            minMaxStack.pop_back();
            if (topValue == minStack.back())
                minStack.pop_back();
            if (topValue == maxStack.back())
                maxStack.pop_back();
        }
        return topValue;
    }

    void push(int number)
    {
        minMaxStack.push_back(number);
        if (maxStack.empty() || number >= maxStack.back())
            maxStack.push_back(number);
        if (minStack.empty() || number <= minStack.back())
            minStack.push_back(number);
    }

    int getMin()
    {
        return minStack.empty() ? 0 : minStack.back();
    }

    int getMax()
    {
        return maxStack.empty() ? 0 : maxStack.back();
    }
};
