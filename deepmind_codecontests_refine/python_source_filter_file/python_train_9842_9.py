from math import pi
d, h, v, e = map(int, input().split())
speed = (4 * v) / pi * d * d

if speed < e:
    print('NO')
else:
    print('YES')
    print(h / (speed - e))
