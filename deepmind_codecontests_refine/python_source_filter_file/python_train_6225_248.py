from math import gcd
a, b = map(int, input().split())
print((a*b) // int(gcd(a,b)))