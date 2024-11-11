import itertools
from bisect import bisect_left,bisect
import sys

n,K=map(int,input().split())
A=list(map(int,input().split()))

A_max=max(A)
lst=[[] for i in range(A_max+1)]
flag=[0]*(A_max+1)
for i in range(n):
    lst[A[i]].append(i)

flag=[0]*n
data=[]
i=0
while flag[i]==0:
    flag[i]=1
    a=A[i]
    b=bisect(lst[a],i)
    if b==len(lst[a]):
        data.append(i)
        i=lst[a][0]+1
    else:
        i=lst[a][b]+1
    if i==n:
        data.append(n)
        i=0

#大丈夫
if not data:
    print()
    sys.exit()
s=len(data)
zzz=data[(K-1)%s]
i=zzz
d=[]
while i<n:
    a=A[i]
    b=bisect(lst[a],i)
    if b<len(lst[a]):
        d.append([i,lst[a][b]])
        i=lst[a][b]+1
        continue
    else:
        i+=1


if d:
    ans=A[zzz:d[0][0]]
    for j in range(len(d)-1):
        ans=list(itertools.chain(ans,A[d[i][1]+1:d[i+1][0]]))
    ans=list(itertools.chain(ans,A[d[-1][1]+1:]))
    print(*ans)
else:
    print(*A[zzz:])