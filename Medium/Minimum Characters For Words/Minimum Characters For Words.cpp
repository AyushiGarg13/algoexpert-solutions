#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> charsForWord(string word)
{
    unordered_map<char, int> chars;
    for (auto chr : word)
    {
        if (chars.find(chr) == chars.end())
            chars[chr] = 1;
        else
            chars[chr]++;
    }
    return chars;
}

void mergeMaps(unordered_map<char, int> singleWordMap, unordered_map<char, int> &totalMap)
{
    for (auto chr : singleWordMap)
    {
        if (totalMap.find(chr.first) == totalMap.end())
            totalMap[chr.first] = chr.second;
        else
            totalMap[chr.first] = max(totalMap[chr.first], chr.second);
    }
}

vector<char> makeListofMap(unordered_map<char, int> map)
{
    vector<char> output;
    for (auto chr : map)
        for (int i = 1; i <= chr.second; i++)
            output.push_back(chr.first);
    return output;
}

vector<char> minimumCharactersForWords(vector<string> words)
{
    unordered_map<char, int> minChars;
    for (auto word : words)
    {
        unordered_map<char, int> singleWordMap = charsForWord(word);
        mergeMaps(singleWordMap, minChars);
    }

    return makeListofMap(minChars);
}