#include <vector>
#include <string>

using namespace std;

string reverseWordsInString(string str)
{
    vector<string> words;
    int i = 0, start_of_word = 0;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            auto word = str.substr(start_of_word, i - start_of_word);
            if (word.length() != 0)
                words.push_back(word);
            words.push_back(" ");
            start_of_word = i + 1;
        }
    }
    words.push_back(str.substr(start_of_word, i - start_of_word));
    string output = "";
    for (auto word : words)
        output = word + output;
    return output;
}
