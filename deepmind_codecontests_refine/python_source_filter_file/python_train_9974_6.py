from itertools import*
from fractions import*
n,*a=map(int,open(0).read().split())
b=list(accumulate([0]+a,gcd))
c=list(accumulate([0]+a[::-1],gcd))
print(max(gcd(s,t)for s,t in zip(b,c[2::-1])))