#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words)
{
    vector<vector<string>> output;
    unordered_map<string, vector<string>> map;
    int index = 0;
    for (auto word : words)
    {
        string temp = word;
        sort(temp.begin(), temp.end());
        map[temp].push_back(word);
    }
    for (auto elem : map)
        output.push_back(elem.second);
    return output;
}
