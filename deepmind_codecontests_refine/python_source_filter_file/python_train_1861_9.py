from math import radians
from cmath import rect

z = 0
deg = 90
while True:
    r, d = map(float, input().split(','))
    if r == d == 0: break
    z += rect(r, radians(deg))
    deg -= d
print(int(z.real), int(z.imag))