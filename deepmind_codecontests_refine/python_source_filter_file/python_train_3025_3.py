import math
a, b, C = map(int, input().split())
rad = C / 180 * math.pi
h = a * math.sin(rad)
S = b * h
c = math.sqrt(h**2 + (b-a*math.cos(rad))**2)
L = a + b + c
print(S, L, h)