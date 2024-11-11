import sys
from collections import defaultdict


def pal(d):
    pr = 0
    for j in range(n // 2):
        if d[j] != d[n - j - 1]:
            pr = 1
            break
    if pr == 0:
        return True
    else:
        return False


def r1(o):
    if o % 2 != 0 and o > 1:
        print("ALICE")
    else:
        print('BOB')


# sys.stdin = open("input.txt")
input = sys.stdin.readline
t = int(input())

for i in range(t):
    n = int(input())
    d = list(input())
    o = d.count('0')
    e = d.count('1')
    if pal(d):
        r1(o)
    else:
        if len(d) % 2 != 0 and o == 2 and d[n // 2] == 0:
            print('DRAW')
        else:
            print('ALICE')
