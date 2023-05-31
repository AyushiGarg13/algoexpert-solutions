def isValidSubsequence(array, sequence):
    sequenceIndex = 0
    for elem in array:
        if sequenceIndex < len(sequence) and elem == sequence[sequenceIndex]:
            sequenceIndex += 1
    return sequenceIndex == len(sequence)
