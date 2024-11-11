import math
A, B = map(int, input().split())
C = A * B // math.gcd(A, B)
print(C)