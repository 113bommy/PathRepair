from collections import*
from bisect import*
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ca=Counter(a)
cb=Counter(b)
for i in a:
  if ca[i]+cb[i]>n:
    print('No')
    exit()
print('Yes')
ba=[bisect(a,i+1) for i in range(n)]
bb=[bisect_left(b,i+1) for i in range(n)]
i=0
for x,y in zip(ba,bb):
  i=max(i,x-y)
ans=b[i:]+b[:i]
print(*ans)