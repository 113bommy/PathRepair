from fractions import gcd
a,b = map(int,input().split())
print(int(a*b/gcd(a,b)))