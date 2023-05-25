#include <string>
using namespace std;

struct Indices
{
    int left;
    int right;
};

Indices getPalindrome(int left, int right, string str)
{
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }
    return Indices{left + 1, right};
}

string longestPalindromicSubstring(string str)
{
    Indices current_longest{0, 1};
    for (int i = 1; i < str.size(); i++)
    {
        int left = i - 1, right = i + 1;
        Indices odd = getPalindrome(i - 1, i + 1, str);
        Indices even = getPalindrome(i - 1, i, str);
        Indices longest = odd.right - odd.left > even.right - even.left ? odd : even;
        current_longest = current_longest.right - current_longest.left >
                                  longest.right - longest.left
                              ? current_longest
                              : longest;
    }

    return string(str.begin() + current_longest.left, str.begin() + current_longest.right);
}
