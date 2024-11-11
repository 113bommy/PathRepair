import math
from functools import reduce

N = int(input())
an = list(map(int,input().split()))

print(reduce(math.gcd, an))