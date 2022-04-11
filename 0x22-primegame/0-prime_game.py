#!/usr/bin/python3
"""
Given a set of consecutive integers starting from 1 up to and including n,
they take turns choosing a prime number from the set and removing that number
and its multiples from the set. The player that cannot make a move loses the
game.
"""


def isWinner(x, nums):
    """
    Prime Game function
    """
    p = 0
    notP = 0

    if nums and x > 0:

        for i in nums:
            if (i > 0):
                if(i % 2 == 0):
                    p += 1
                else:
                    notP += 1

        if p >= notP:

            return "Maria"
        else:
            return "Ben"

    else:
        return None
