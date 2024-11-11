from math import *
from random import *
cr = 2
h = 1
mas = []
for i in range(50000):
    mas.append(cr)
    cr = cr + h + (h + 1) * 2
    h += 1
for t in range(int(input())):
    cnt = 0
    n = int(input())
    while n > 1:
        l = 0
        r = 50000 - 1
        while r - l > 1:
            m = (l + r) // 2
            if (mas[m] <= n):
                l = m
            else:
                r = m
        cnt += 1
        n -= mas[l]
    print(cnt)