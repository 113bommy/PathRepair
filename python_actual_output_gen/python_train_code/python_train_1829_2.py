import bisect as bi
import collections as cc
I=lambda:list(map(int,input().split()))
f=cc.defaultdict(int)
n,=I()
l=I()
ans=0
for i in range(n):
    d[l[i]+i]+=1
    ans+=d[i-l[i]]
print(ans)
    
    
    