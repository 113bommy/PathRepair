# import itertools as it
# import functools as ft
import math

teststring = """5
3
1 1 1
2 2 2
3 3 3
4
1 2 1 2
2 1 2 1
3 4 3 4
7
1 3 3 1 1 1 1
2 4 4 3 2 2 4
4 2 2 2 4 4 2
3
1 2 1
2 3 3
3 1 2
10
1 1 1 2 2 2 3 3 3 1
2 2 2 3 3 3 1 1 1 2
3 3 3 1 1 1 2 2 2 3
"""
online = __file__ != "/home/jhli/py/Grakn/Problem_A.py"
true, false = True, False
if True:

    def spitout():
        for c in teststring.splitlines():
            yield c


    _ito = spitout()

    if not online:
        def input():
            return next(_ito)


    def build_enum(*a):
        built = dict()
        for i, c in enumerate(a):
            built[c] = i
        return lambda x: built[x]
# T = 1
T = int(input())
##-----------------start coding-----------------
for ti in range(1, T + 1):
    n = int(input())
    a = []
    b = []
    c = []
    p = []
    a.extend(map(int, input().split(" ")))
    b.extend(map(int, input().split(" ")))
    c.extend(map(int, input().split(" ")))

    l = len(a)    
    p.append(a[0])
    for i in range(1, l-1):
        if (a[i] != p[i-1]):
            p.append(a[i])
        elif (b[i] != p[i-1]):
            p.append(b[i])
        else:
            p.append(c[i])
    
    if l >= 2:
        if (p[l-2] != a[l-1] and a[l-1] != a[0]):
            p.append(a[l-1])
        elif (p[l-2] != b[l-1] and b[l-1] != b[0]):
            p.append(b[l-1])
        else:
            p.append(c[l-1])
    
    print(" ".join(map(str, p)))
    # print('Case #{}: {}'.format(ti, '...'))

