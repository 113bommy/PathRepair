from copy import *
from collections import*
n=int(input())
if n==1:
    print(1)
    exit()
p=[list(map(int,input().split()))for i in range(n)]
l=[]
for i in range(n):
    q=deepcopy(p)
    a,b=q.pop(i)
#    print(a,q)
    l.extend([(s-a,t-b)for s,t in q])
print(n-(Counter(l).most_common()[0][1]+1)+1)