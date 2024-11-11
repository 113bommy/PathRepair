from math import gcd
a, b = map(int, input().split())
gd = gcd(a, b)
print(a*b//gd)