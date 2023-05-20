#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<vector<int>> stableInternships(vector<vector<int>> interns, vector<vector<int>> teams)
{
    unordered_map<int, int> chosenInterns;
    stack<int> freeInterns;
    vector<int> currentInternChoices(interns.size(), 0);
    vector<unordered_map<int, int>> teamInternsMap;
    for (int i = 0; i < interns.size(); i++)
        freeInterns.push(i);

    for (int i = 0; i < teams.size(); i++)
    {
        unordered_map<int, int> rank;
        for (int j = 0; j < teams.size(); j++)
            rank[teams[i][j]] = j;
        teamInternsMap.push_back(rank);
    }

    while (!freeInterns.empty())
    {
        int currentIntern = freeInterns.top();
        freeInterns.pop();
        int choice = currentInternChoices[currentIntern];
        int teamChoiceForIntern = interns[currentIntern][choice];
        currentInternChoices[currentIntern]++;
        if (chosenInterns.find(teamChoiceForIntern) == chosenInterns.end())
            chosenInterns[teamChoiceForIntern] = currentIntern;
        else
        {
            int previousIntern = chosenInterns[teamChoiceForIntern];
            if (teamInternsMap[teamChoiceForIntern][currentIntern] <
                teamInternsMap[teamChoiceForIntern][previousIntern])
            {
                freeInterns.push(previousIntern);
                chosenInterns[teamChoiceForIntern] = currentIntern;
            }
            else
                freeInterns.push(currentIntern);
        }
    }

    vector<vector<int>> output;
    for (auto pair : chosenInterns)
        output.push_back({pair.second, pair.first});

    return output;
}
