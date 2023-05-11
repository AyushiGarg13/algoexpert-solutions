#include <unordered_map>
#include <string>
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

bool generateDocument(string characters, string document)
{
    unordered_map<char, int> input_freq;
    count_frequency(characters, input_freq);
    for (auto s : document)
    {
        if (input_freq.find(s) == input_freq.end() || input_freq[s] < 1)
            return false;
        input_freq[s]--;
    }
    return true;
}
