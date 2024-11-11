from math import *

q = int(input())
for i in range(q):
    w = int(input())
    e = [int(a) for a in input().split()]
    r = 0
    for j in range(w):
        r += e[j]
    g = 0
    for h in range(2, ceil(sqrt(r))):
        if r % h == 0:
            g = 1
            break
    z = 0
    if g == 0:
        print(w - 1)
        for sd in range(w):
            if (r - e[sd]) % 2 == 0:
                z = sd
                break
        for nm in range(w - 1):
            if nm != z:
                print(nm + 1, end=' ')
        if w - 1 != z:
            print(w)
    else:
        print(w)
        for nm in range(w - 1):
            print(nm + 1, end=' ')
        print(w)