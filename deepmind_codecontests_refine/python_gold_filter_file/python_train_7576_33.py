from fractions import *
n,*a=map(int,open(0).read().split())
mod=10**9+7
b=a[0]
for i in a:
    b=b*i//gcd(b,i)
print(sum(b//i for i in a)%mod) 