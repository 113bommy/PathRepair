import math
a,b,C = map(int, input().split())
S = a * b * math.sin(math.radians(C)) / 2
L = a + b + math.sqrt(a**2 + b**2 - a*b*math.cos(math.radians(C)))
h = 2 * S / a
print(S)
print(L)
print(h)

