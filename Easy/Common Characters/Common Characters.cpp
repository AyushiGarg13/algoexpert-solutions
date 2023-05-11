#include <vector>
#include <unordered_set>
using namespace std;

vector<string> commonCharacters(vector<string> strings)
{
    vector<string> output;
    int smallest = 0;
    for (int i = 1; i < strings.size(); i++)
        if (strings[i].size() < strings[smallest].size())
            smallest = i;

    unordered_set<char> potential_char_set(strings[smallest].begin(), strings[smallest].end());

    for (int i = 0; i < strings.size(); i++)
    {
        unordered_set<char> str_set(strings[i].begin(), strings[i].end());
        unordered_set<char> chars_to_remove;
        for (auto chr : potential_char_set)
            if (str_set.find(chr) == str_set.end())
                chars_to_remove.insert(chr);

        for (auto chr : chars_to_remove)
            potential_char_set.erase(chr);
    }
    for (auto chr : potential_char_set)
        output.push_back(string(1, chr));
    return output;
}