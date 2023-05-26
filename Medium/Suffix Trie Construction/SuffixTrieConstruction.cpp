#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str)
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void insertSubstringStartingAtIndex(int i, string str)
    {
        TrieNode *node = root;
        for (int j = i; j < str.size(); j++)
        {
            auto letter = str[j];
            if (node->children.find(letter) == node->children.end())
                node->children[letter] = new TrieNode();
            node = node->children[letter];
        }
        node->children[endSymbol] = nullptr;
    }

    void populateSuffixTrieFrom(string str)
    {
        for (int i = 0; i < str.size(); i++)
            insertSubstringStartingAtIndex(i, str);
    }

    bool contains(string str)
    {
        TrieNode *node = root;
        for (auto letter : str)
        {
            if (node->children.find(letter) == node->children.end())
                return false;
            node = node->children[letter];
        }
        return node->children.find(endSymbol) != node->children.end();
    }
};
