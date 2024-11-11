import math
A, B = [int(_) for _ in input().split()]
print(A * B // math.gcd(A, B))
