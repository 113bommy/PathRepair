#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS():return [list(x) for x in sys.stdin.readline().split()]
def S():
    res = list(sys.stdin.readline())
    if res[-1] == "\n":
        return res[:-1]
    return res
def IR(n):
    return [I() for i in range(n)]
def LIR(n):
    return [LI() for i in range(n)]
def SR(n):
    return [S() for i in range(n)]
def LSR(n):
    return [LS() for i in range(n)]

sys.setrecursionlimit(1000000)
mod = 1000000007

def solve():
    H,W,h,w = LI()
    if W%w != 0:
        s = [0]+[100000]*(w-1)
        for i in range(W-w+1):
            s.append(s[-w]-1)
        a = [s[i]-s[i-1] for i in range(1,W+1)]
        print("Yes")
        for i in range(H):
            print(*a)
    elif H%h != 0:
        H,W,h,w = W,H,w,h
        s = [0]+[100000]*(w-1)
        for i in range(W-w+1):
            s.append(s[-w]-1)
        a = [s[i]-s[i-1] for i in range(1,W+1)]
        print("Yes")
        ans = [[a[i]]*W for i in range(H)]
        for i in range(H):
            print(*ans[i])
    else:
        print("No")
    return

#Solve
if __name__ == "__main__":
    solve()
