#!/usr/bin/env python3


def ri():
    return map(int, input().split())

"""
u ur r dr d dl l
"""


def direction(x, y):
    if x == 0 and y > 0:
        return 0
    elif x > 0 and x == y:
        return 1
    elif y == 0 and x > 0:
        return 2
    elif x > 0 and x == y:
        return 3
    elif x == 0 and y < 0:
        return 4
    elif x < 0 and x == -y:
        return 5
    elif x < 0 and y == 0:
        return 6
    elif x < 0 and x == -y:
        return 7
    else:
        return -1


def dist(x, y):
    return max(abs(x), abs(y))


r = set()
b = set()
n = int(input())
x0, y0 = ri()
mm = [[2*10**9 + 2, 2*10**9 + 2, 'none'] for i in range(8)]

for i in range(n):
    w, x, y = input().split()
    x = int(x)
    y = int(y)
    x = x - x0
    y = y - y0

    d = direction(x, y)
    if d == -1:
        continue
    elif mm[d][0]**2 + mm[d][1]**2 > x**2 + y**2 or mm[d][2] == 'none':
        mm[d] = [x, y, w]

for i, m in enumerate(mm):
    if (m[2] == 'Q') or ((m[2] == 'R') and (i % 2 == 0)) or (m[2] == 'B' and i % 2 == 1):
        print('YES')
        exit()

print('NO')
