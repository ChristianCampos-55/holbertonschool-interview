#!/usr/bin/python3
"""
Calculates how much water will be retained after it rains
"""


def rain(walls):
    """
    Rain function
    """
    if type(walls) is not list:
        return 0
    if len(walls) is 0:
        return 0
    if (len(walls) < 2):
        return 0
    return sum([i for i in walls[1:-1] if i > 0])
