#!/usr/bin/python3
"""
Script that reads stdin line by line and computes its metrics
"""
import sys
stcd = {"200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0}
sumatory = 0


def print_stats():
    """
    Function that prints log stats
    """
    global sumatory

    print('File size: {}'.format(sumatory))
    stcdor = sorted(stcd.keys())
    for each in stcdor:
        if stcd[each] > 0:
            print('{}: {}'.format(each, stcd[each]))


if __name__ == "__main__":
    cnt = 0
    try:
        for data in sys.stdin:
            try:
                fact = data.split(' ')
                if fact[-2] in stcd:
                    stcd[fact[-2]] += 1
                sumatory += int(fact[-1])
            except:
                pass
            cnt += 1
            if cnt == 10:
                print_stats()
                cnt = 0
    except KeyboardInterrupt:
        print_stats()
        raise
    else:
        print_stats()