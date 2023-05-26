#include <string>
#include <math.h>
using namespace std;

bool oneEdit(string stringOne, string stringTwo)
{
    if (abs(int(stringOne.size() - stringTwo.size())) > 1)
        return false;
    bool flag = false;
    int i = 0, j = 0;
    while (i < stringOne.size() && j < stringTwo.size())
    {
        if (stringOne[i] != stringTwo[j])
        {
            if (flag)
                return false;
            flag = true;
            if (stringOne.size() > stringTwo.size())
                i++;
            else if (stringOne.size() < stringTwo.size())
                j++;
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            i++;
            j++;
        }
    }

    return true;
}
