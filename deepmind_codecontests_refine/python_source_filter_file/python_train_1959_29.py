import fraction
from functools import reduce

N = int(input())
As = map(int, input().split())

print(reduce(fraction.gcd, As))
