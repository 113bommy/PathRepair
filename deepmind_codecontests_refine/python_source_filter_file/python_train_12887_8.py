N=int(input())
*L,=map(int,input().split())

L.sort()
from bisect import*
i=0
ans=0
for i in range(N-1):
    for j in range(i+1,N):
        ans+=bisect_left(L[j:],L[i]+L[j])-1

print(ans)