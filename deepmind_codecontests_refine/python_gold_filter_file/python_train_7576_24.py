from fractions import gcd
from functools import reduce
lcm=lambda x,y:x//gcd(x,y)*y
MOD=10**9+7

n=int(input())
A=list(map(int,input().split()))

c=sum(pow(a,MOD-2,MOD) for a in A)%MOD
l=reduce(lcm,A)%MOD

print(c*l%MOD)
