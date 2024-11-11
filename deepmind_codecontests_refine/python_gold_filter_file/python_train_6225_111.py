from math import gcd
a,b = map(int,input().split())
val = gcd(a,b)
print(a*b//val)