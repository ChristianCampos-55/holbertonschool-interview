#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes
Return True or False if all boxes can be accesed
"""


def canUnlockAll(boxes):
    """
    A method that determines if all the boxes can be opened
    """
    keys = [0]
    for i in keys:
        for currentBox in boxes[i]:
            if currentBox not in keys and currentBox < len(boxes):
                keys.append(currentBox)
    if len(keys) == len(boxes):
        return True
    return False
