from math import gcd
from functools import reduce
n=int(input())
a=list(map(int,input().split()))
k=reduce(lambda x,y:x*y//gcd(x,y),a)
ans=sum(list(map(lambda x:k//x,a)))
print(ans%(10**9+7))
