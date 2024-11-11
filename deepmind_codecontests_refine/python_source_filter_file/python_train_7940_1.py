import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,k = inpl()
a = inpl()
if k != 0:
    b = inpl()
pre = 0
bad = False
for i in range(k-1):
    lind = b[i]-1; rind = b[i+1]-1
    l = a[lind]; r = a[rind]
    if r-l < rind-lind: bad = True
if bad: print(-1); quit()
l = []; r = []; dv = []
if k == 0:
    l = [-INF]; r = [INF]; dv = [a]
else:
    for _,i in enumerate(b):
        dv.append(a[pre:i-1])
        if pre == 0: l.append(-INF)
        else: l.append(a[pre-1])
        r.append(a[i-1])
        pre = i
    dv.append(a[pre:])
    l.append(a[pre-1]); r.append(INF)
# print(dv,l,r)
res = 0
for i in range(k+1):
    li = []
    L = l[i]+1; R = r[i]-1
    ln = len(dv[i])
    for j,x in enumerate(dv[i]):
        if L+j <= x <= R-ln+j:
            li.append(x-i)
    dp = [INF] * (len(li))
    for i,x in enumerate(li):
        ind = bisect_right(dp,x)
        dp[ind] = x
    ans = len(li)
    for i,x in enumerate(dp):
        if x == INF:
            ans = i
            break
    res += ln-ans
print(res)