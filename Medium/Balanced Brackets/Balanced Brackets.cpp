#include <string>
#include <stack>
using namespace std;

bool balancedBrackets(string str)
{
    stack<char> bracketStack;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            bracketStack.push(str[i]);

        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (bracketStack.empty())
                return false;
            auto topElement = bracketStack.top();
            if ((topElement == '(' && str[i] == ')') ||
                (topElement == '[' && str[i] == ']') ||
                (topElement == '{' && str[i] == '}'))
                bracketStack.pop();
            else
                return false;
        }
    }

    return bracketStack.empty();
}
