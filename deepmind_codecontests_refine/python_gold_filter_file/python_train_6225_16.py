import math
A, B = [int(i) for i in input().split()]
print((A * B) // math.gcd(A, B))
