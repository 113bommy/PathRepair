from collections import defaultdict as d
from itertools import accumulate as ac
n,k=map(int,input().split())
a=[0]+list(ac(list(map(int,input().split()))))
b=d(int)
c=0
for i in range(n+1):
    p=(a[i]-i)%k
    c+=b[p]
    b[p]+=1
    if i-k>=0:
        b[(a[i-k]-i+k)%k]-=1
print(c)