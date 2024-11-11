from math import gcd
a, b = map(int, input().split())
c = gcd(a, b)
print(a*b//c)