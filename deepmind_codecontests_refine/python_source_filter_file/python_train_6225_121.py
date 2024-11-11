import math
a,b=map(int,input().split())
c=int(a*b//math.gcd(a,b))
print(c)