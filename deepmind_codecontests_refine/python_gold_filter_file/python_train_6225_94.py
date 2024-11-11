a,b = map(int,input().split())
from fractions import gcd
print(a//gcd(a,b) * b)
