#include <vector>
#include <math.h>
using namespace std;

int firstDuplicateValue(vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		int index_mapped = abs(array[i]) - 1;
		if (array[index_mapped] < 0)
			return abs(array[i]);
		else
			array[index_mapped] *= -1;
	}
	return -1;
}
