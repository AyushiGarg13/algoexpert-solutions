#include <vector>
#include <string>
#include <stack>
using namespace std;

int reversePolishNotation(vector<string> tokens)
{
    stack<int> tokenStack;
    for (string op : tokens)
    {
        if (op == "+" || op == "-" || op == "*" || op == "/")
        {
            int second = tokenStack.top();
            tokenStack.pop();
            int first = tokenStack.top();
            tokenStack.pop();
            int answer = 1;
            if (op == "+")
                answer = first + second;
            else if (op == "-")
                answer = first - second;
            else if (op == "*")
                answer = first * second;
            else
                answer = (int)first / (int)second;

            tokenStack.push(answer);
        }
        else
            tokenStack.push(stoi(op));
    }
    return tokenStack.top();
}
