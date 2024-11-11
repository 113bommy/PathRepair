import math

a, b = list(map(int, input().split()))

x1 = a - b
x2 = a + b

if x1 < 0:
    print(-1)
elif x1 == 0:
    print('%.12f' % (x2 / 2))
else:
    res2 = x2 / (2 * math.floor((a + b) / (2 * b)))
    print('%.12f' % res2)