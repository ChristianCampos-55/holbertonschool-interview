#!/usr/bin/python3
"""
    calculates Pascals' triangle
"""


def pascal_triangle(n):
    """Pascal Triangle"""
    anu = []
    if n <= 0:
        return anu
    for i in range(n):
        c = [1]
        if anu:
            for j in range(i):
                c.append(sum(anu[-1][j:j+2]))
        a.append(c)
    return anu
