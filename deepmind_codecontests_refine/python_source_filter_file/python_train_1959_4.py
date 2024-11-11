from functools import reduce
from math import gcd

n = int(input())
a = list(map(int,input().split()))


print(reduce(gcd,a))
