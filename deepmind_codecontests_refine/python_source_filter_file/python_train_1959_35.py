import math
from functools import reduce
n = int(input())
li = list(map(int,input().split())
print(reduce(math.gcd,li))
