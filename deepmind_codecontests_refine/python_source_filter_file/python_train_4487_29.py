import sys
import math
import bisect

def input():
    return sys.stdin.readline().strip()

def iinput():
    return int(input())

def finput():
    return float(input())

def tinput():
    return input().split()

def rinput():
    return map(int, tinput())

def rlinput():
    return list(rinput())

def modst(a, s):
    res = 1
    while s:
        if s % 2:
            res *= a
        a *= a
        s //= 2
    return res

def size(x1, y1, x2, y2):
    return ((x1 + x2) ** 2 + (y1 + y2) ** 2) ** 0.5

def d(sum_size, size_x_y):
    rerurn (sum_size ** 2 - 8 * size_x_y) ** 0.5

def main():
    n = iinput()
    a = rlinput()
    a.sort()
    if n == 1:
        return 0
    q = 1e7
    for i in range(1, n):
        q = min(q, a[i + n - 1] - a[i])
    return min((a[2 * n - 1] - a[0]) * q, (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]))
    
print(main())