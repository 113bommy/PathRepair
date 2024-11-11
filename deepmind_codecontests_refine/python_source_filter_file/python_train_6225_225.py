import math

A,B = map(int,input().split())

R = (A * B) // math.gcd(A, B)

print(R)