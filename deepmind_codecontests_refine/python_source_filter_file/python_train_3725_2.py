import math
a, b, h, m = map(int, input().split())

l = a**2 + b**2 - 2*a*b*math.cos(math.radians(6*m-0.5*h*60))
print(math.sqrt(l))