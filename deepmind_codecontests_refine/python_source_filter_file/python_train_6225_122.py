import math
a,b = map(int,input().split())

g = a*b/math.gcd(a,b)
print(g)
