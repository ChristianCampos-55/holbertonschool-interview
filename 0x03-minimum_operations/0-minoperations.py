#!/usr/bin/python3
"""
Module used to min ops
"""


def minOperations(n):
    """
    Determines if boxes can be opened or not
    """

    if (not isinstance(n, int)):
        return 0
    if (n < 2):
        return 0
    result = 0
    a = 2
    while a <= n:
        if n % a == 0:
            result += a
            n = n / a
            a = a - 1
        a = a + 1
    return int(result)
