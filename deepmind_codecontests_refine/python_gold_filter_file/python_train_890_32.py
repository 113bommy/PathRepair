import math
n,m,z=map(int,input().split())
print(z//((m*n)//math.gcd(m,n)))