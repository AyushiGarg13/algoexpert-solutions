#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
	int index = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] == sequence[index])
			index++;
		if (index == sequence.size())
			return true;
	}
	return false;
}
