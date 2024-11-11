a, b = map(int, input().split())
from fractions import gcd
print(a * b // gcd(a, b))