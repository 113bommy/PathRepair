import math

x, y, r = 0, 0, 90
while True:
    d, t = map(float, input().split(","))
    if d == t == 0:
        break
    x += r * math.cos(math.radians(r))
    y += r * math.sin(math.radians(r))
    r -= t
print(int(x))
print(int(y))