from functools import reduce
from fractions import gcd
n,x = map(int,input().split())
X = list(map(int,input().split()))
X = [abs(x-X[0]) for x in X]
print(reduce(gcd,X))