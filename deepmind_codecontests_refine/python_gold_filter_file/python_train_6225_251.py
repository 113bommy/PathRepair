import math
a, b = [int(x) for x in input().split()]
print(a*b//math.gcd(a,b))
