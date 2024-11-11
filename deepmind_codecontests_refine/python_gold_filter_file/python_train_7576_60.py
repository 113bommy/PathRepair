from fractions import gcd
from functools import reduce
mod=10**9+7
n=int(input())
a=[int(i) for i in input().split()]
l=reduce(lambda x,y:x//gcd(x,y)*y,a)
ans=sum(map(lambda x:l//x,a))
print(ans%mod)