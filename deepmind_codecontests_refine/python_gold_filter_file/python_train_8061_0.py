import sys
import math


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    bcost = [0] * m
    for i in range(m - 2, -1, -1):
        valstoright = m - i - 1
        bcost[i] = bcost[i + 1] + valstoright * (b[i + 1] - b[i])
    acost = [0] * n
    for i in range(1, n):
        valstoleft = i
        acost[i] = acost[i-1] + valstoleft * (a[i] - a[i-1])
    res = 10000000000000000
    for i in range(m):
        amax = n - 1
        amin = 0
        while amin < amax:
            avg = (amin + amax + 1) // 2
            if a[avg] > b[i]: amax = avg - 1
            else: amin = avg
        # if a[amin] > b[i]: continue
        res = min(res, bcost[i] + acost[amin] + (amin+1)*(b[i] - a[amin]))
    for i in range(n):
        bmax = m - 1
        bmin = 0
        while bmin < bmax:
            avg = (bmax + bmin) // 2
            if b[avg] < a[i] : bmin = avg + 1
            else: bmax = avg
        # if b[bmin] < a[i]: continue
        # print(i, bmin, bcost[bmin], acost[i], (m - bmin)*(b[bmin] - a[i]))
        res = min(res, bcost[bmin] + acost[i] + (m - bmin)*(b[bmin] - a[i]))
    return max(res, 0)





if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
print(solve())