from math import pi

d, h, v, e = map(int, input().split())

r = d / 2
bottom_area = pi * r * r
speed = bottom_area * e

if speed < v:
    delta = v - speed
    water = bottom_area * h
    time = water / delta
    print('YES\n{}'.format(time))
else:
    print('NO')
