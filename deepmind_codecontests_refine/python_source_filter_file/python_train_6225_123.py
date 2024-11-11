import math
a,b=map(int,input().split())
c=a*b//math.gcd(a,b)
print(c)