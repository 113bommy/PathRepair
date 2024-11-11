from collections import defaultdict
from bisect import bisect,bisect_left
N = int(input())
XYU = [input().split() for _ in range(N)]
for i in range(N):
    XYU[i][0] = int(XYU[i][0])
    XYU[i][1] = int(XYU[i][1])
dp = defaultdict(lambda :defaultdict(list))
dn = defaultdict(lambda :defaultdict(list))
d1 = defaultdict(lambda :defaultdict(list))
d2 = defaultdict(lambda :defaultdict(list))

for i in range(N):
    x,y,u = XYU[i]
    dp[u][x+y].append(x)
    dn[u][x-y].append(x)
    d1[u][x].append(y)
    d2[u][y].append(x)

for u in ['U','R','D','L']:
    for z in dp[u]:
        dp[u][z].sort()
    for z in dn[u]:
        dn[u][z].sort()
    for z in d1[u]:
        d1[u][z].sort()
    for z in d2[u]:
        d2[u][z].sort()

ans = float('inf')
for i in range(N):
    x,y,u = XYU[i]
    if u=='U':
        j = bisect_left(dp['R'][x+y],x)-1
        if j>=0:
            ans = min(ans,10*(x-dp['R'][x+y][j]))
        j = bisect(dn['L'][x-y],x)
        if j<len(dn['L'][x-y]):
            ans = min(ans,10*(dn['L'][x-y][j]-x))
        j = bisect(d1['D'][x],y)
        if j<len(d1['D'][x]):
            ans = min(ans,5*(d1['D'][x][j]-y))
    elif u=='D':
        j = bisect_left(dn['R'][x-y],x)-1
        if j>=0:
            ans = min(ans,10*(x-dn['R'][x-y][j]))
        j = bisect(dp['L'][x+y],x)
        if j<len(dp['L'][x+y]):
            ans = min(ans,10*(dp['L'][x+y][j]-x))
        j = bisect_left(d1['U'][x],y)-1
        if j>=0:
            ans = min(ans,5*(y-d1['U'][x][j]))
    elif u=='R':
        j = bisect(dp['U'][x+y],x)
        if j<len(dp['U'][x+y]):
            ans = min(ans,10*(dp['U'][x+y][j]-x))
        j = bisect(dn['D'][x-y],x)
        if j<len(dn['D'][x-y]):
            ans = min(ans,10*(dn['D'][x-y][j]-x))
        j = bisect(d2['L'][y],x)
        if j<len(d2['L'][y]):
            ans = min(ans,5*(d2['L'][y][j]-x))
    elif u=='L':
        j = bisect_left(dp['D'][x+y],x)-1
        if j>=0:
            ans = min(ans,10*(x-dp['D'][x+y][j]))
        j = bisect_left(dn['U'][x-y],x)-1
        if j>=0:
            ans = min(ans,10(x-dn['U'][x-y][j]))
        j = bisect_left(d2['R'][y],x)-1
        if j>=0:
            ans = min(ans,5*(x-d2['R'][y][j]))

if ans==float('inf'):
    ans = 'SAFE'
    print(ans)
else:
    print(ans)
