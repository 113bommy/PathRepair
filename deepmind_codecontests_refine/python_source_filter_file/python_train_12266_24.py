from functools import reduce
from math import gcd

X = int(input().split()[1])
x = [abs(int(x) - X) for x in input().split()]

print(reduce(gcd, x))
