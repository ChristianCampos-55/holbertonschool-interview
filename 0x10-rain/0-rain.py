#!/usr/bin/python3
"""
Calculates how much water will be retained after it rains
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    """
    if len(walls) is 0:
        return 0
    if (len(walls) < 2):
        return 0
    counter = 0
    for flatter, medder in enumerate(walls):
        if flatter is not 0 and flatter is not (len(walls) - 1):
            left = max(walls[0:flatter])
            right = max(walls[flatter + 1:len(walls)])
            if medder < left and medder < right:
                counter += min([left, right]) - medder
    return counter
