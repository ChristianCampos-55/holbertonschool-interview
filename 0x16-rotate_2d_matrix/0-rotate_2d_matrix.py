#!/usr/bin/python3
"""
Rotates a matrix 90 degrees
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees.
    """
    clone = matrix[:]

    for i in range(len(matrix)):
        col_i = [row[i] for row in clone]
        matrix[i] = col_i[::-1]
