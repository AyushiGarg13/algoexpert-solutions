def tournamentWinner(competitions, results):
    current_best_team = ""
    map = {current_best_team: 0}

    for i in range(len(competitions)):
        winning_team_index = 1 if results[i] == 0 else 0
        winning_team = competitions[i][winning_team_index]
        if winning_team not in map:
            map[winning_team] = 3
        else:
            map[winning_team] += 3

        if map[winning_team] > map[current_best_team]:
            current_best_team = winning_team
    return current_best_team
