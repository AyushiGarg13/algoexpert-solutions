#include <vector>
#include <string>
using namespace std;

void push_to_output(int count, vector<char> &output, string str, int i)
{
    while (count > 9)
    {
        output.push_back(9 + 48);
        output.push_back(str[i - 1]);
        count -= 9;
    }
    output.push_back(count + 48);
    output.push_back(str[i - 1]);
}

string runLengthEncoding(string str)
{
    vector<char> output;
    int count = 1, i;
    for (i = 1; i < str.size(); i++)
    {
        if (str[i - 1] == str[i])
            count++;
        else
        {
            push_to_output(count, output, str, i);
            count = 1;
        }
    }
    push_to_output(count, output, str, i);
    return string(output.begin(), output.end());
}
