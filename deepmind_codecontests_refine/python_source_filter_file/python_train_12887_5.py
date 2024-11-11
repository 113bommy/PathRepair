N=int(input())
*L,=map(int,input().split())

L.sort()
from bisect import*
i=0
ans=0
while i<N:
    j=i+1
    while j<N:
        ans+=bisect_left(L[j:],L[i]+L[j])-1
        j+=1
    i+=1

print(ans)