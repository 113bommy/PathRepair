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

n,m = inpl()
x = inpl()
p = inpl()
g = x[1]-x[0]
for i in range(1,n-1):
    g = math.gcd(g,x[i+1]-x[i])
for i,y in enumerate(p):
    if y == g:
        print('YES')
        print(x[0],i+1)
        break
else:
    print('NO')