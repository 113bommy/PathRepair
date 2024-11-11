# Python 3
from math import gcd
a, b, x, y = list(map(int, input().split()))
g = gcd(x, y)
x /= g
y /= g
k = min(a // x, b // y)
print(k * x, k * y)
