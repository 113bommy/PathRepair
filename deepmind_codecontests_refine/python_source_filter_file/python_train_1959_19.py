import math
from functools import reduce
N = int(input())
a = list(map(int, input().split()))
print(reduce(math.gcd, a))