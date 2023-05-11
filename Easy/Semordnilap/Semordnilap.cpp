#include <unordered_set>
using namespace std;

vector<vector<string>> semordnilap(vector<string> words)
{
    unordered_set<string> occurance;
    vector<vector<string>> output;
    for (auto w : words)
    {
        string pal = w;
        reverse(pal.begin(), pal.end());
        if (occurance.find(pal) != occurance.end())
            output.push_back({w, pal});
        else
            occurance.insert(w);
    }
    return output;
}
