import sys
from collections import Counter
ip=lambda :sys.stdin.readline().rstrip()
n=int(ip())
a=list(map(int,ip().split()))
b=list(map(int,ip().split()))
d={a[i]:i for i in range(n)}
e={b[i]:i for i in range(n)}
c=[]
for i in range(1,n+1):
    c.append(d[i]-e[i])
ans=0
c=Counter(c)
for i in c:
    if i<0:
        ans=max(ans,c[i]+c.get(n+i,0))
    else:
        ans=max(ans,c[i]+c.get(n-i,0))
print(ans)