import math
n,m=map(int,input().split())
print(int(n*m/math.gcd(n,m)))
