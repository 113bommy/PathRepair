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
def inpsl(x): tmp = sys.stdin.readline(); return list(tmp[:x])
def err(x): print(x); exit()

n,m,d = inpl()
c = inpl()
res = [0]*(n+1)
idx = [[-1,-1] for _ in range(m)]
now = n
for i in range(m)[::-1]:
    idx[i][1] = now
    for x in range(c[i]):
        res[now] = i+1
        now -= 1
    idx[i][0] = now+1
# print(res,idx)
now = 0
for i in range(m):
    nx = now+d
    if nx>n or res[nx]: break
    for j in range(idx[i][0],idx[i][1]+1):
        res[j] = 0
    for j in range(nx,min(n-1,nx+c[i])):
        res[j] = i+1
        now = j
else:
    if now+d<n+1: err('NO')
print('YES')
print(*res[1:])
