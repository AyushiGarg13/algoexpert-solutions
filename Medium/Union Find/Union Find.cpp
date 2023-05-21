#include <optional>
#include <unordered_map>
using namespace std;

class UnionFind
{
    unordered_map<int, int> disjoint_set;
    unordered_map<int, int> rank;

public:
    void createSet(int value)
    {
        disjoint_set[value] = value;
        rank[value] = 0;
    }

    optional<int> find(int value)
    {
        if (disjoint_set.find(value) == disjoint_set.end())
            return nullopt;
        if (disjoint_set[value] != value)
            disjoint_set[value] = *find(disjoint_set[value]);
        return disjoint_set[value];
    }

    void createUnion(int valueOne, int valueTwo)
    {
        if (disjoint_set.find(valueOne) == disjoint_set.end() ||
            disjoint_set.find(valueTwo) == disjoint_set.end())
            return;
        int val_1_ID = *find(valueOne);
        int val_2_ID = *find(valueTwo);
        if (val_1_ID == val_2_ID)
            return;
        else
        {
            if (rank[val_1_ID] < rank[val_2_ID])
                disjoint_set[val_1_ID] = val_2_ID;
            else if (rank[val_1_ID] > rank[val_2_ID])
                disjoint_set[val_2_ID] = val_1_ID;
            else
            {
                disjoint_set[val_2_ID] = val_1_ID;
                rank[val_1_ID]++;
            }
        }
    }
};
