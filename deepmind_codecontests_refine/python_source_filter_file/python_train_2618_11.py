def inp():
    return map(int, input().split())


c = 0


def divide(x):
    global c
    if x == 1:
        return
    if x % 2 == 0:
        divide(x // 2)
    elif x % 3 == 0:
        divide(x // 3)
    else:
        exit(print(-1))
    c += 1


from math import *

n, m = inp()
if n % m:
    exit(print(-1))
divide(m // n)
print(c)
