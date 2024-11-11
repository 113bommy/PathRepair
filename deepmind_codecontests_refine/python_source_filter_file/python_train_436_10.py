import sys
from math import ceil
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

for _ in range(int(ri())):
    n = int(ri())
    a = Ri()
    ans = []
    minn = INF
    maxx = -1
    for i in range(len(a)):
        if i-1 >=0 and a[i-1] == -1 and a[i] != -1:
            minn = min(minn,a[i])
            maxx = max(maxx,a[i])
        elif i+1 <= n-1 and a[i+1] == -1 and a[i] != -1:
            minn = min(minn,a[i])
            maxx = max(maxx,a[i])
    
    if minn == INF:
        print(0,0)
    else:
        summ = (minn+maxx)//2
        for i in range(len(a)):
            if a[i] == -1:
                a[i] = summ
        m=-1
        print(a)
        for i in range(1,len(a)):
            m = max(m,abs(a[i]-a[i-1]))
        print(m,summ)