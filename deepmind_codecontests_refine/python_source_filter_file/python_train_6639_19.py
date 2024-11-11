n=int(input())
a=list(map(int,input().split()))
a.sort()
f=[1]*(10**6+1)
from collections import Counter
c=Counter(a)
ans=0
for ai in a:
  if c[ai]==1 and f[ai]==1:ans+=1
  if f[ai]==1:
    for i in range(ai,10**6,ai):
      f[i]=0
print(ans)

