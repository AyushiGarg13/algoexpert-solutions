def sortedSquaredArray(array):
    left = 0
    right = len(array)-1
    output = []
    while(left <= right):
        if array[left]**2 > array[right]**2:
            output.append(array[left]**2)
            left += 1
        else:
            output.append(array[right]**2)
            right -= 1
    return output[::-1]
