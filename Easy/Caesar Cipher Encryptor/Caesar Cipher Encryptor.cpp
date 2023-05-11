#include <vector>
#include <numeric>
#include <string>
using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    vector<char> s;
    key = key % 26;
    for (int i = 0; i < str.size(); i++)
    {
        s.push_back(str[i]);
    }
    for (int i = 0; i < str.size(); i++)
    {
        int newcode = s[i] + key;
        s[i] = newcode <= 122 ? newcode : 96 + newcode % 122;
    }
    return string(s.begin(), s.end());
}
