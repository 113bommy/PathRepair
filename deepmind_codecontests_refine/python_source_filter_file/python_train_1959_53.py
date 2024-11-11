from math import *
from functools import *

n = int(input())
print(reduce(gcd, map(int, input().split())))
