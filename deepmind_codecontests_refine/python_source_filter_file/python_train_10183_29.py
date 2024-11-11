import sys
import math 
ni = lambda: int(ns())
na = lambda: list(map(int, input().split()))
ns = lambda: input()
N,K = na()
S = [na() for i in range(N)]
S.sort(key=lambda x:x[1],reverse=True)
res = []
tmp=0
d=set([])
ds = []
for t,dd in S[:K]:
    tmp+=dd
    if t in d:
        ds.append(dd)
    else:
        d.add(t)
ans = tmp + len(d)**2
ax = ans

for t,dd in S[K:]:
    if len(d)==0:
        break
    if t not in d:
        ax +=2*len(d)+1
        ax += dd-ds.pop()
        d.add(t)
        ans = max(ax,ans)
print(ans)