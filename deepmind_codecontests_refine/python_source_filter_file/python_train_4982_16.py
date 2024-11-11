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
def S(): return list(sys.stdin.readline())[:-1]
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
"""
a,b = LS()
if a == b:
    print("H")
else:
    print("D")
"""

#B
"""
w,a,b = LI()
print(max(max(a,b)-min(a,b)-w,0))
"""

#C
"""

x = I()
a = 0
i = 1
while a < x:
    a += i
    i += 1
print(i-1)
"""

#D
n,k = LI()
a = LI()
a.sort()
a = a[:bisect.bisect_left(a,k)]
n = len(a)
a = a[::-1]
l = -1
r = n
while r-l > 1:
    m = (l+r)//2
    k_ = k-a[m]
    dp = [0]*k
    dp[0] = 1
    ma = 1
    for i in range(n):
        if i == m:continue
        ai = a[i]
        for j in range(min(ma,k-ai))[::-1]:
            j_ = j+ai
            if dp[j]:
                if k_ <= j_:
                    l = m
                    break
                dp[j_] = 1
                if j_ > ma:
                    ma = j_
        else:
            continue
        break
    else:
        r = m
print(n-r)
#E

#F

#G

#H

#I

#J

#K

#L

#M

#N

#O

#P

#Q

#R

#S

#T
