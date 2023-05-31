def nonConstructibleChange(coins):
    current_sum = 0
    coins = sorted(coins)
    for coin in coins:
        if coin > current_sum + 1:
            return current_sum + 1
        else:
            current_sum += coin
    return current_sum + 1
