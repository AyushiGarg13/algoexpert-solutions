#include <unordered_map>
using namespace std;

void count_frequency(string str, unordered_map<char, int> &freq)
{
    for (auto s : str)
    {
        if (freq.find(s) == freq.end())
            freq[s] = 1;
        else
            freq[s]++;
    }
}

int firstNonRepeatingCharacter(string string)
{
    unordered_map<char, int> freq;
    count_frequency(string, freq);
    for (int i = 0; i < string.size(); i++)
    {
        if (freq[string[i]] == 1)
            return i;
    }
    return -1;
}
