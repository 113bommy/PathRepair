from math import *
# minimum jumps jack can take
x = int(input())
if x < 0:
    x = -x
n = (sqrt(1 + 8 * x) - 1) / 2
s = 0
minx = floor(n) + 1
if (sqrt(1 + 8 * x) - 1) % 2 == 0:
    s = n
else:
    if x % 2 == 0:
        h = 0
        while h < 3:
            if ((minx + h) * (minx + h + 1) / 2) % 2 == 0:
                s = minx + h
                break
            h = h + 1
    else:
        h = 1
        while h < 3:
            if ((minx + h) * (minx + h + 1) / 2) % 2 != 0:
                s = minx + h
                break
            h = h + 1

print(int(s))
