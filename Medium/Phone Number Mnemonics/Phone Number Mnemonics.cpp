#include <vector>
#include <unordered_map>
using namespace std;

void helper(int idx, string phoneNumber, vector<char> current_mnemonic,
            vector<string> &mnemonics, unordered_map<int, vector<char>> numberLetterMap)
{
    if (idx == current_mnemonic.size())
        mnemonics.push_back(string(current_mnemonic.begin(), current_mnemonic.end()));
    else
    {
        auto digit = phoneNumber[idx];
        auto letters = numberLetterMap[digit];
        for (auto letter : letters)
        {
            current_mnemonic[idx] = letter;
            helper(idx + 1, phoneNumber, current_mnemonic, mnemonics, numberLetterMap);
        }
    }
}

vector<string> phoneNumberMnemonics(string phoneNumber)
{
    vector<string> mnemonics;
    vector<char> current_mnemonic(phoneNumber.size());
    unordered_map<int, vector<char>> numberLetterMap = {
        {'0', {'0'}},
        {'1', {'1'}},
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
    helper(0, phoneNumber, current_mnemonic, mnemonics, numberLetterMap);

    return {mnemonics};
}
