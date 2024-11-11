from fractions import gcd
n,m=map(int,input().split())
print(3*(n-gcd(n,m))