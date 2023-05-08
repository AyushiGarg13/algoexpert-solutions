#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results)
{
    string current_best_team = "";
    unordered_map<string, int> winners = {{current_best_team, 0}};
    for (int i = 0; i < competitions.size(); i++)
    {
        string comp_win = competitions[i][abs(results[i] - 1)];
        if (winners.find(comp_win) == winners.end())
            winners[comp_win] = 3;
        else
            winners[comp_win] += 3;

        if (winners[comp_win] > winners[current_best_team])
            current_best_team = comp_win;
    }
    return current_best_team;
}
