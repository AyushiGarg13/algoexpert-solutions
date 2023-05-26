#include <vector>
#include <string>
using namespace std;

bool isValidIP(string str)
{
    int str_int = stoi(str);
    if (str_int > 255)
        return false;
    return str.size() == to_string(str_int).size();
}

string constructIPAddress(vector<string> ipAddressParts)
{
    string str = "";
    for (int i = 0; i < ipAddressParts.size(); i++)
    {
        str += ipAddressParts[i];
        if (i < ipAddressParts.size() - 1)
            str += '.';
    }

    return str;
}

vector<string> validIPAddresses(string str)
{
    vector<string> output;
    for (int i = 1; i < min(int(str.size()), 4); i++)
    {
        vector<string> current_IP_addresses = {"", "", "", ""};
        current_IP_addresses[0] = string(str.begin(), str.begin() + i);
        if (!isValidIP(current_IP_addresses[0]))
            continue;
        for (int j = i + 1; j < i + min(int(str.size()) - i, 4); j++)
        {
            current_IP_addresses[1] = string(str.begin() + i, str.begin() + j);
            if (!isValidIP(current_IP_addresses[1]))
                continue;
            for (int k = j + 1; k < j + min(int(str.size()) - j, 4); k++)
            {
                current_IP_addresses[2] = string(str.begin() + j, str.begin() + k);
                current_IP_addresses[3] = string(str.begin() + k, str.end());
                if (isValidIP(current_IP_addresses[2]) && isValidIP(current_IP_addresses[3]))
                    output.push_back(constructIPAddress(current_IP_addresses));
            }
        }
    }

    return output;
}
