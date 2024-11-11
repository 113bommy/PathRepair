import math
from math import cos, sin

a,b,C=map(float,input().split())
C = math.radians(C)
S = 0.5*a*b*sin(C)
L = math.sqrt(b**2+a**2-2*a*b*cos(C))
h = 2*S / a

print(S)
print(L)
print(h)