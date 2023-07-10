def binarySearch(array, target):
    left = 0
    right = len(array) - 1
    while left <= right:
        mid = (left + right)//2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
