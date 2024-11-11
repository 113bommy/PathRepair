from math import gcd
A, B = map(int, input().split())

print(int(A * B / gcd(A, B)))