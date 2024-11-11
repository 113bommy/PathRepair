import sys
from itertools import *
from math import *
def solve():
    n,m,c = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    bsum = [0] * m
    for i in range(m):
        bsum[i] = (bsum[i-1] if i > 0 else 0) + b[i]
    for i in range(n):
        a[i] += bsum[i if i < m else m - 1]
        dont = m - (n - i) - 1
        a[i] -= b[dont] if m > dont >= 0 else 0
        a[i] %= c
    print(' '.join(map(str, a)))








if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
solve()