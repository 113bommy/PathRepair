n=int(input())
a=list(map(int,input().split()))
l=[0]
r=[0]
ans=0
from  fractions import gcd
for i in range(n-1):
    l.append(gcd(l[i],a[i]))
    r.append(gcd(r[i],a[-1-i]))
for i in range(n):
    ans=max(ans,gcd(l[i],r[-1-i]))

print(ans)
