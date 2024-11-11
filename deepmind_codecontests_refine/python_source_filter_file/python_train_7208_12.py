import math
l = int(input())
g = list()
for i in range(l):
    n, m, k = map(int, input().split())
    e = n // k
    if e >= m:
        g.append(m)
    else:
        r = e
        m -= e
        while m >= 0:
            r -= 1
            m -= k
        g.append(r)
for i in g:
    print(i)