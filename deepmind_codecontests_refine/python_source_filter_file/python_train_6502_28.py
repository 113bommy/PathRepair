# cook your dish her
from math import *
n,m=map(int,input().split())
def printNcR(n, r):
    if(n==1):
        return 0
    p = 1
    k = 1
    if (n - r < r):
        r = n - r
    if (r != 0):
        while (r):
            p *= n
            k *= r
            m = gcd(p, k)
            p //= m
            k //= m
            n -= 1
            r -= 1
    else:
        p = 1
    return p
if(n%m==0):
    kmin=m*printNcR(int(n/m),2)
else:
    a=n%m
    b=int(n/m)
    kmin=a*printNcR(b+1,2)+(b-a)*printNcR(b,2)
p=m-1
q=n-p
kmax=printNcR(q,2)
print(kmin,kmax)