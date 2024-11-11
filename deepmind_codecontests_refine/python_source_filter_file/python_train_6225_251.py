import math

a,b = [int(i) for i in input().split()]

print(a*b//math.gcd(a, b))