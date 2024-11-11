a,b=map(int,input().split())
from fractions import gcd
print(int(a*b/gcd(a,b)))