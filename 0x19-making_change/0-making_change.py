#!/usr/bin/python3
"""Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount"""


def makeChange(coins, total):
    """ Basically adds arrays """

    if total <= 0:
        return 0
    if (coins is None or len(coins) == 0):
        return -1
    change = 0
    c = sorted(coins, reverse=True)
    s = total
    for coin in c:
        while (s % coin >= 0 and s >= coin):
            change += int(s / coin)
            s = s % coin
    change = change if s == 0 else -1
    return change
