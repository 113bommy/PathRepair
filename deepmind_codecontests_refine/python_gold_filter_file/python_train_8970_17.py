from collections import defaultdict as dd
n,k=map(int,input().split())
g=dd(list)
for i in map(int,input().split()):
    cnt=0
    while i>0:g[i].append(cnt);i//=2;cnt+=1
    g[0].append(cnt)
ans=999999999999999999999
for i in g:
    if len(g[i])>=k:ans=min(ans,sum(sorted(g[i])[:k]))
print(ans)