import math

A, B = map(int, input().split())

myans = (A * B) // math.gcd(A, B)

print(myans)