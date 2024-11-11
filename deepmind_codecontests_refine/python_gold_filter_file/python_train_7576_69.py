from fractions import *
n,*a=map(int,open(0).read().split())
b=1
for i in a:b*=i//gcd(b,i)
print(sum(b//i for i in a)%(10**9+7)) 
