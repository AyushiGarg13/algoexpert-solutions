#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array)
{
    int i, product = 1;
    vector<int> output(array.size(), 1);
    for (i = 0; i < array.size(); i++)
    {
        output[i] = product;
        product *= array[i];
    }
    product = 1;
    for (i = array.size() - 1; i >= 0; i--)
    {
        output[i] *= product;
        product *= array[i];
    }
    return output;
}
