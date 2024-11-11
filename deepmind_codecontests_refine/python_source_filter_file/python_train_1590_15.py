import math
from sys import stdin
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")


n, = gil()
a = gil()
a.sort()
dp = {}

def cal(c):
    c = max(c, 0)
    if c not in dp :
        cst = 0
        for i in range(n):
            cst += abs(a[i]-c**i)
        dp[c] = cst
    return dp[c]

l, r = 0, int(a[-1]**(1/(n-2)))
# print(r)
idx = None

while l <= r:
    mid = (l+r)//2
    if cal(mid) > cal(mid-1):
        r = mid-1
    else:
        l = mid + 1
        idx =  mid

print(cal(idx))