def sortedSquaredArray(array):
    left, right = 0, len(array)-1
    index = right
    output = [0] * len(array)
    while(left <= right):
        if array[left]**2 > array[right]**2:
            output[index] = array[left]**2
            left += 1
        else:
            output[index] = array[right]**2
            right -= 1
        index -= 1
    return output
