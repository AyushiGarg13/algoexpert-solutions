def transposeMatrix(matrix):
    output = []
    for i in range(len(matrix[0])):
        output.append([])
        for j in range(len(matrix)):
            output[i].append(matrix[j][i])
    return output
