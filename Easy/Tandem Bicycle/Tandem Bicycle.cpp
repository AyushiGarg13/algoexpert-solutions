#include <vector>
#include <algorithm>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest)
{
    fastest ? sort(redShirtSpeeds.begin(), redShirtSpeeds.end(), greater<int>()) : sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    int totalSpeed = 0;
    for (int i = 0; i < redShirtSpeeds.size(); i++)
        totalSpeed += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
    return totalSpeed;
}
