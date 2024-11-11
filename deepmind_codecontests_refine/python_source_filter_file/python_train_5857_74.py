from math import *

def r1(t):
    return t(input())

def r2(t):
    return [t(i) for i in input().split()]

for _ in range(r1(int)):
    n, r = r2(int)
    if n >= r:
        print(r*(r + 1) // 2)
    else:
        print(n * (n - 1) // 2 + 1)
