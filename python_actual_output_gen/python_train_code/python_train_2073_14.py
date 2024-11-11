N,M,Q=map(int,input().split())
ABCD=[list(map(int,input().split())) for i in range(Q)]
from itertools import combinations
ans=0
for p in combinations(range(N+M),M):
    r=0
    for a,b,c,d in ABCD:
        if p[b-1]-b+1-p[a-1]+a-1==c:
            r+=d
    ans=max(ans,r)
print(ans)