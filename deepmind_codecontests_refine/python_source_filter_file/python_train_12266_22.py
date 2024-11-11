from functools import reduce
from fractions import gcd
n,x=map(int,input().split())
x=[abx(x-int(i)) for i in input().split()]
print(reduce(gcd,x))