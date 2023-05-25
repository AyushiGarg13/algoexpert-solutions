#include <string>
#include <vector>
using namespace std;

string bestDigits(string number, int numDigits)
{
    vector<char> output;
    for (int i = 0; i < number.size(); i++)
    {
        while (!output.empty() && output.back() < number[i] && numDigits > 0)
        {
            output.pop_back();
            numDigits--;
        }
        output.push_back(number[i]);
    }
    while (numDigits > 0)
    {
        output.pop_back();
        numDigits--;
    }

    return string(output.begin(), output.end());
}
