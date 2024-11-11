import math
n,m,z=map(int,input().split())
print(z//((n*m)//(math.gcd(n,m))))