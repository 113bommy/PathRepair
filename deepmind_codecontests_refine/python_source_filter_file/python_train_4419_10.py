import sys
from math import log2,floor,ceil,sqrt
# import bisect
# from collections import deque

Ri = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD = 10**9+7

n  =int(ri())
vis = []
for i in range(n):
    c,p = Ri()
    vis.append([c,p,i])
t = int(ri())
r = Ri()
r = [[r[i],i] for i in range(t)]
r.sort(key = lambda x : x[0])
vis.sort(key = lambda x : (x[1],-x[0]),reverse = True)
ans = 0
flag = [True]*t
tcus = []
for i in range(n):
    tf=  -1
    cus=  vis[i]
    for j in range(t):
        if cus[0] <= r[j][0] and flag[j]:
            tf = j
            break
    if tf != -1:
        flag[tf] = False
        ans+=cus[1]
        tcus.append([i,tf])
print(len(tcus),ans)
for i in range(len(tcus)):
    cus = tcus[i][0]
    t = tcus[i][1]
    print(vis[cus][2]+1, t+1)