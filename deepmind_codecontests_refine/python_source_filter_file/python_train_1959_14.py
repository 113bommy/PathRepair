import functools
import math

n = int(input())
A = list(map(int, input().split()))

print(functools.reduce(math.gcd, A))