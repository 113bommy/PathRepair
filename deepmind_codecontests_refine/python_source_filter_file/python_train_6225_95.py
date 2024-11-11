a,b=map(int,input().split())
from math import gcd
print(int(a*b/gcd(a,b)))