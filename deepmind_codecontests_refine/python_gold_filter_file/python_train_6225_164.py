from fractions import gcd
a,s=map(int,input().split())
print(a*s//gcd(a,s))