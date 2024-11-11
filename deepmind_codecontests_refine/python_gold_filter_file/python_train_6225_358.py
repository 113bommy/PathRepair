import math

A, B = [int(s) for s in input().split()]
print(A * B // math.gcd(A, B))