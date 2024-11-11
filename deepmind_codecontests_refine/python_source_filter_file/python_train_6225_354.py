a, b = map(int, input().split())
from math import gcd
print(a*b // gcd(a, b))