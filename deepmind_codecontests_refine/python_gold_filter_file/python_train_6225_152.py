import math
A, B = list(map(int, input().split()))

print(A * B // math.gcd(A, B))