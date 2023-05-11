#include <string>
using namespace std;

bool isPalindrome(string str)
{
    int start = 0, end = str.size() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
