n,m=map(int,input().split())
a=list(map(int,input().split()))
from collections import Counter
c=[0]
for i in a:
    c.append((c[-1]+a)%m)
cc=Counter(c)
ans=0
for i in cc.values():
    ans+=i*(i-1)//2
print(ans)
