#!/usr/bin/python3
"""rotate_2d_matrix task"""


def rotate_2d_matrix(matrix):
    matrix_size = len(matrix)

    for layer in range(matrix_size // 2):
        start = layer
        end = matrix_size - 1 - layer
        for i in range(start, end):
            top = matrix[start][i]
            matrix[start][i] = matrix[end - i + start][start]
            matrix[end - i + start][start] = matrix[end][end - i + start]
            matrix[end][end - i + start] = matrix[i][end]
            matrix[i][end] = top
