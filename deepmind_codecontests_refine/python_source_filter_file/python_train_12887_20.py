n=int(input())
l=list(map(int,input().split()))
l.sort()

import bisect

ans=0
for i in range(n-2):
  for j in range(i+1,n-1):
    ind=bisect.bisect_left(temp,l[i]+l[j])
    ans+=n-ind
print(ans)