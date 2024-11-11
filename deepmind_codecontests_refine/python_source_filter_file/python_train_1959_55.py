import math
from functools import reduce

input()
print(reduce(math.gcd, map(int, input().split())))
