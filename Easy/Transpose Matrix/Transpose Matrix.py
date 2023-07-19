def transposeMatrix(matrix):
    output = [[] for _ in range(len(matrix[0]))]
    for i in range(len(matrix[0])):
        for j in range(len(matrix)):
            output[i].append(matrix[j][i])
    return output
