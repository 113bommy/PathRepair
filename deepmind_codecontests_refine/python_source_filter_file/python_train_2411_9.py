import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify, nlargest
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
 
n = inp()
a = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
 
d = defaultdict(int)
z = set()
yp = set()
xp = set()
for i in range(n):
    for j in range(i+1,n):
        x1,y1 = a[i]; x2,y2 = a[j]
        Y = y2-y1; X = x2-x1
        if X < 0: Y *= -1; X *= -1
        if X == 0:
            xp.add(x1)
        elif Y == 0:
            yp.add(y1)
        else:
            g = math.gcd(X,abs(Y))
            X //= g; Y //= g
            c = y1*x2-x1*y2
            if (X,Y,c) in z: continue
            d[(X,Y)] += 1
            z.add((X,Y,c))
m = len(z) + len(yp) + len(xp)
res = 0
for x,y,c in list(z):
    res += m-d[(x,y)]
for YY in list(yp):
    res += m-len(yp)
for XX in list(xp):
    res += m-len(xp)
print(res//2)