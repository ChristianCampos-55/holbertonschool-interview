#!/usr/bin/python3
import sys

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        n = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)

    a = []

    def q(row, n, a):
        if row == n:
            print(a)
        else:
            for column in range(n):
                p = [row, column]
                if valid(a, p):
                    a.append(p)
                    q(row + 1, n, a)
                    a.remove(p)

    def valid(a, p):
        for q in a:
            if q[1] == p[1]:
                return False
            if q[0] + q[1] == p[0] + p[1]:
                return False
            if q[0] - q[1] == p[0] - p[1]:
                return False
        return True

    q(0, n, a)
