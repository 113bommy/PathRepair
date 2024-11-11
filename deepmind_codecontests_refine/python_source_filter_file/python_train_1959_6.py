import fraction
from functools import reduce

n = int(input())
a = list(map(int, input().split()))

print(reduce(fraction.gcd, a))