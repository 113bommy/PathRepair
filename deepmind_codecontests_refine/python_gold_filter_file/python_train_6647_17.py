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

#A
def A():
    n = I()
    a = LI()
    s = 0
    for i in a:
        s ^= (i%2)
    if s:
        print("NO")
    else:
        print("YES")
    return

#B
def B():
    n = I()
    a = LI()
    m = n*(n+1)>>1
    s = sum(a)
    if s%m:
        print("NO")
        return
    k = s//m
    b = [k+a[i-1]-a[i] for i in range(n)]
    s = 0
    for i in b:
        if i%n or i < 0:
            print("NO")
            return
        s += i//n
    if s == k:
        print("YES")
    else:
        print("NO")
    return

#C
def C():
    n = I()

    return

#D
def D():
    n = I()

    return

#E
def E():
    n = I()

    return

#F
def F():
    n = I()

    return

#Solve
if __name__ == "__main__":
    B()
