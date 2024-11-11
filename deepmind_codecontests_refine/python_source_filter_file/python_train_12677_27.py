from bisect import bisect_left as bl
from itertools import accumulate as ac
n,m,k=map(int,input().split())
a=list(ac([0]+list(map(int,input().split()))))
b=list(ac([0]+list(map(int,input().split()))))
l=0
for i in range(n+1):
    if k<a[i]:
        break
    else:
        l=max(l,i+bl(b,k-a[i])-1)
print(l)