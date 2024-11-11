from math import gcd as g
a, b = map(int, input().split())
print((a*b)//g(a,b))