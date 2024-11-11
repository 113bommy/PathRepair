a, b = map(int, input().split())
from fraction import gcd
print(a*b // gcd(a, b))