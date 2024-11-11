n=int(input())
a=list(map(int,input().split()))
cur=a[-1]
from math import gcd
for i in range(1,n-1):
    cur=gcd(cur,a[i])
if (cur !=a[0]) and (a[0]!=1):
    print(-1)
else:
    print(2*n)
    for i in a:
        print(i,a[0],end=' ')
