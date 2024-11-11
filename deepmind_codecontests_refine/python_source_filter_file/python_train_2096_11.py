import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify, nlargest
from copy import deepcopy
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_1(): return list(map(lambda x:int(x)-1, sys.stdin.readline().split()))
def inps(): return sys.stdin.readline()
def inpsl(x): tmp = sys.stdin.readline(); return tmp[:x]
def err(x): print(x); exit()

for _ in range(inp()):
    ang = inp()
    res = -1
    for n in range(3,181):
        for k in range(1,n-1):
            if 180*k == ang*n:
                res = n
                break
        if res != -1: break
    print(res)