from functools import reduce
from math import gcd
n=int(input())
A=list(map(int,input().split()))
lc=reduce(lambda a,b: a*b//gcd(a,b),A)
b=[lc//i for i in A]
print(sum(b)%(1000*1000000+7))
