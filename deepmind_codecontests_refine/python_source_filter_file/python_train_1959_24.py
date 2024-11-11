from functools import reduce
from math import gcd

n = input()
a = list(map(int, input().split()))

print(reduce(gcd, a))
