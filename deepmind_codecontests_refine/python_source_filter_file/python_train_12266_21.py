from functools import reduce
from fractions import gcd

N,X=map(int,input().split())
x=[abs(i-X) for i in input().split()]

print(reduce(gcd,x))