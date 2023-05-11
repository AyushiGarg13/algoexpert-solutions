#include <vector>
#include <algorithm>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights)
{
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort(blueShirtHeights.begin(), blueShirtHeights.end());
    bool pos_difference;
    pos_difference = redShirtHeights[0] - blueShirtHeights[0] > 0 ? true : false;
    for (int i = 0; i < redShirtHeights.size(); i++)
    {
        if (pos_difference && (redShirtHeights[i] - blueShirtHeights[i] <= 0))
            return false;
        else if (!pos_difference && (redShirtHeights[i] - blueShirtHeights[i] >= 0))
            return false;
    }
    return true;
}
