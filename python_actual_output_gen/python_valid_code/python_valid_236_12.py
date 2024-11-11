#!/usr/bin/env python3
import sys

#lines = stdin.readlines()
def rint():
    return map(int, sys.stdin.readline().split())

def input():
    return sys.stdin.readline().rstrip('\n')

def oint():
    return int(input())


t = oint()

for _ in range(t):
    n, x, y = rint()
    c = x + y

    #best
    c1 = c+1
    fx = c+1 - n
    if fx <= 0:
        ans1 = 1
    else:
        ans1 = fx
    #worst
    ans2 = min(n, x+y-1)
    print(ans1, ans2)


