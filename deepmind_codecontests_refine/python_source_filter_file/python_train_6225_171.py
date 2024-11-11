import math

a, b = map(int, input().split())
t = math.gcd(a, b)
print(a // t * b)
