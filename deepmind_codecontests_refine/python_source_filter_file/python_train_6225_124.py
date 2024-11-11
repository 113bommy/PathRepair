import math
a,b=map(int,input().split())
s=a*b//math.gcd(a, b)
print(s)