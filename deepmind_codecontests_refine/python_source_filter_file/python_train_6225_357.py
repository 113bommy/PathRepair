import math

A, B = [int(n) for n in input().split()]

print((A * B) // math.gcd(A, B))
