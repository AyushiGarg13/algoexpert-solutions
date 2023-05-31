def twoNumberSum(array, targetSum):
    map = set()
    for num in array:
        if targetSum - num in map:
            return [num, targetSum - num]
        else:
            map.add(num)
    return []
