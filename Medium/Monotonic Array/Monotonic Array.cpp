#include <vector>
using namespace std;

bool isMonotonic(vector<int> array)
{
	int iflag = 1, dflag = 1;
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i - 1] <= array[i])
			continue;
		else
		{
			iflag = 0;
			break;
		}
	}
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i - 1] >= array[i])
			continue;
		else
		{
			dflag = 0;
			break;
		}
	}
	return iflag || dflag;
}
