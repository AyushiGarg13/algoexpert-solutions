#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg)
{
    
    int min_miles = 0, miles_left = 0, min_city_index = 0;
    for (int i = 1; i < fuel.size(); i++)
    {
        miles_left += (fuel[i - 1] * mpg) - distances[i - 1];
        if (miles_left < min_miles)
        {
            min_miles = miles_left;
            min_city_index = i;
        }
    }
    return min_city_index;
}
