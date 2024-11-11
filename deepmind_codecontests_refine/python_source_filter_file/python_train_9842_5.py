from math import pi

d, h, v, e = map(int, input().split())
t = (-pi * d ** 2 / 4) / (pi * d ** 2 / 4 * e - v)
print('YES\n' + str(t) if t > 0 else 'NO')
